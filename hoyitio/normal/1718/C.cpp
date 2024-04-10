#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	auto mul = [](long long a, long long b, long long p)->long long
	{
        return(__int128)a * b % p; 
        //return (a * b - (LL)(a / (long double)p * b + 1e-3) * p + p) % p;
    };
    auto power = [&](long long a, long long r, long long p)
	{
        long long res = 1;
        for(; r; a = mul(a, a, p), r >>= 1)
            if(r & 1) res = mul(res, a, p);
        return res;
    };
	auto isprime = [&](long long n)
	{
        static long long p[9] = {2,61};
        if(n==1 or n==46856248255981LL)return false;
        if(n == 2) return true;
        if(not(n & 1)) return false;
        long long d = n - 1, r = 0;
        for(;not(d & 1); d >>= 1) r += 1;
        bool res = true;
        for(int i = 0; i < 2 and p[i] < n and res; i += 1)
		{
            long long x = power(p[i], d, n);
            if(x == 1 or x == n - 1) continue;
            for(int j = 1; j < r; j += 1)
			{
                x = mul(x, x, n);
                if(x == n - 1) break;
            }
            if(x != n - 1) res = false;
        }
        return res;
    };
	int T;
	cin>>T;
	while(T--)
	{
		int n,q;
		cin>>n>>q;
		vector<int> dvs;
		vector<long long> a(n+5);
		for(int i=1;i<n;i++)
		{
			if(n%i==0 and isprime(n/i))
				dvs.push_back(i);
		}
//		for(auto z:dvs)cerr<<"d :"<<z<<endl;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int sz=dvs.size();
		vector<multiset<long long>> st(sz);
		vector<vector<long long>> sum(sz);
		for(int t=0;t<sz;t++)
		{
			int d=dvs[t];
			sum[t].resize(d);
			for(int i=0;i<n;i++)
				sum[t][i%d]+=a[i];
			for(int i=0;i<d;i++)
			{
//				cerr<<"init "<<d<<' '<<i<<' '<<sum[t][i]<<endl;
				st[t].insert(sum[t][i]);
			}
		}
		auto getans=[&]()
		{
			long long ans=0;
			for(int t=0;t<sz;t++)
			{
				int d=dvs[t];
				ans=max(ans,d**--st[t].end());
			}
			return ans;
		};
		cout<<getans()<<"\n";
		while(q--)
		{
			int pos,val;
			cin>>pos>>val;
			pos--;
			int del=val-a[pos];
			for(int t=0;t<sz;t++)
			{
				int d=dvs[t];
				st[t].erase(st[t].find(sum[t][pos%d]));
				sum[t][pos%d]+=del;
				st[t].insert(sum[t][pos%d]);
			}
			a[pos]=val;
			cout<<getans()<<"\n";
		}
	}
	
	return 0;
}
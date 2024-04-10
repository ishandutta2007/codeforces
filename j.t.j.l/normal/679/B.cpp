#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

typedef pair<long long, long long> PLL;

PLL ans;

map<int, PLL> mp;

PLL gao(long long x, long long Y){
//	cout<<x<<' '<<Y<<endl;
	if (mp.find(x) != mp.end())
		return mp[x];
	long long y = exp(log(x) / 3) + 2;
	while(y * y * y > x)
		y--;
	if (y >= Y){
		y = Y - 1;
		x = Y * Y * Y - 1;
	}
	if (mp.find(x) != mp.end())
		return mp[x];
	if (y <= 0)
		return PLL(0, 0); 
	long long z = x / (y * y * y);
	PLL A = gao(x - y * y * y * z, y), B = gao(x - y * y * y * (z - 1), y);
	A.first += z, A.second += y * y * y * z;
	B.first += z - 1, B.second += y * y * y * (z - 1);
	PLL C = max(A, B);
	mp[x] = C;
	return C;
}

int main(){
	long long m;
	cin>>m;
	mp.clear();
	mp[0] = PLL(0, 0);
	ans = gao(m, MAXN);
	cout<<ans.first<<' '<<ans.second<<endl;
	/*
	int n = 0;
	for(int i = 1; i < N; i++)
		a[i] = 0;
	long long x = m;
	long long now = 0;
	while(x){
		long long y = exp(log(m) / 3) + 2;
		while(y * y * y > x)
			y--;
		a[y] = x / (y * y * y);
		now += a[y];
		x -= a[y] * y * y * y;
		b[y] = x;
	}
	ans = PLL(now, m);
	long long tmp = 0;
	for(int i = N - 1; i >= 1; i--){
		if (a[i]){
			tmp += a[i] - 1;
			long long x = b[y] + (long long)i * i * i;
			PLL Nico = work(x);
			Nico.first += tmp;
			ans = max(ans, tmp);
		}
	}
	cout<<ans.first<<' '<<ans.second<<endl;*/
	return 0;
}
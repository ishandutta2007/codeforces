#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n;
		string str;
		cin>>str;
		cin>>k;
		vector<int> good(26);
		set<int> sp,rem;
		string t;
		for(int i=1;i<=k;i++)
		{
			cin>>t;
			good[t[0]-'a']=1;
		}
		for(int i=0;i<n;i++)
		{
			rem.insert(i);
			if(good[str[i]-'a'])
			{
				sp.insert(i);
			}
		}
		int cnt=0,ok=1;
		while(ok)
		{
//			cerr<<"round "<<cnt<<endl;
			ok=0;
			auto it=sp.begin();
			while(it!=sp.end())
			{
				auto it2=rem.lower_bound(*it);
				if(it2!=rem.begin())
				{
					--it2;
//					cerr<<"erase "<<*it2<<endl;
					sp.erase(*it2);
					rem.erase(it2);
					ok=1;
				}
				++it;
			}
			cnt++;
		}
		cout<<cnt-1<<"\n";
	}
	
	return 0;
}
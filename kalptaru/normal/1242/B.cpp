#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
int main()
{
	
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m;
		cin>>n>>m;
		int a,b;
		map<ll,ll> gra;
		FOR(i,0,m)
		{
			cin>>a>>b;
			gra.insert({1000000*(a-1) + b-1,1});
			gra.insert({1000000*(b-1) + a-1,1});
		}
		bool vis[n]={0};
		set<int> unv;
		FOR(i,0,n)
		unv.insert(i);
		queue<int> now;
		set<int> nows;
		int i,j;
		int grp=0;
		while(unv.size()>0)
		{
				j=*unv.begin();
				unv.erase(j);
				grp++;
				now.push(j);
				while(now.size()>0)
				{
					i=now.front();
					now.pop();
					vector<int> tem;
					for(auto it=unv.begin(); it!=unv.end() ; it++)
					{
						if(gra[i*1000000+ (*it) ]==0)
						{
							now.push(*it);
							tem.push_back(*it);
						}
					}
					FOR(r,0,tem.size())
					unv.erase(tem[r]);
					tem.clear();
				}
		}
		cout<<grp-1;
	}
	return 0;
}
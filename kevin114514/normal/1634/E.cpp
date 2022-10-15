#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
map<int,int> M,M2,M3;
vector<int> v[100100];
string ans[100100];
int cc[100100];
map<int,pii> M4;
map<pii,pii> M5;
set<int> pos[100100];
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int n;
		cin>>n;
		while(n--)
		{
			int x;
			cin>>x;
			M[x]++;
			v[i].pb(x);
		}
	}
	set<int> s;
	for(auto p:M)
		s.insert(p.first);
	for(auto x:s)
	{
		if(M[x]%2)
			die("NO");
		M[x]/=2;
	}
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		M2.clear();
		for(auto x:v[i])
			M2[x]++;
		set<int> st;
		for(auto p:M2)
			st.insert(p.first);
		for(auto x:st)
			M2[x]/=2;
		ans[i].resize(sz(v[i]));
		for(int j=0;j<sz(v[i]);j++)
		{
			int x=v[i][j];
			if(M2[x])
			{
				if(M3[x])
					M2[x]--,
					M[x]--;
//				cnt++;
				if(!M3[x])
					ans[i][j]='L',
					cnt++;
				else	ans[i][j]='R';
				M3[x]^=1;
				v[i][j]=-1;
			}
		}
		M3.clear();
		cc[i]=cnt;
	}
//	bool flag=0;
	set<pii> b; 
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<sz(v[i]);j++)
		{
			int x=v[i][j];
			if(x==-1)
				continue;
			if(M4[x]!=mp(0,0))
			{
				M5[M4[x]]=mp(i,j);
				M5[mp(i,j)]=M4[x];
				M4[x]=mp(0,0);
			}
			else	M4[x]=mp(i,j);
			pos[i].insert(j);
			b.insert(mp(i,j));
//			flag=1;
		}
	}
	{
//		char c='L';
		while(sz(b))
		{
			pii p=*b.begin();
			while(true)
			{
				b.erase(p);
				pos[p.first].erase(p.second);
				ans[p.first][p.second]='L';
				p=M5[p];
				b.erase(p);
				pos[p.first].erase(p.second);
				ans[p.first][p.second]='R';
				if(sz(pos[p.first]))
					p.second=*pos[p.first].begin();
				else break;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=m;i++)
		puts(ans[i].c_str());
	return 0;
}
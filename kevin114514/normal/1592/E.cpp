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
void die(string S){puts(S.c_str());exit(0);}
int number[1001000][22];
int psum[1001000][22];
int pos[1001000][2];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=0;j<=20;j++)
		{
			number[i][j]=(x>>j);
			psum[i][j]=psum[i-1][j]^number[i][j];
		}
	}
	int ans=0;
	for(int j=0;j<=20;j++)
	{
		for(int i=0;i<1001000;i++)
			pos[i][0]=pos[i][1]=1e9;
		pos[0][0]=0;
		vector<int> v[2];
		v[0].pb(0);
		for(int i=1;i<=n;i++)
		{
			if(number[i][j]&1)
			{
//				if(s[i%2].lower_bound(mp(psum[i][j+1],-1))!=s[i%2].end())
//				{
//					pii p=*s[i%2].lower_bound(mp(psum[i][j+1],-1));
//					if(p.first==psum[i][j+1])
//						ans=max(ans,i-p.second);
//				}
				ans=max(ans,i-pos[psum[i][j+1]][i%2]);
			}
			else
			{
				for(int jj=0;jj<2;jj++)
					for(int k=0;k<sz(v[jj]);k++)
						pos[psum[v[jj][k]][j+1]][jj]=1e9;
				v[0].clear();
				v[1].clear();
			}
//			s[i%2].insert(mp(psum[i][j+1],i));
			pos[psum[i][j+1]][i%2]=min(pos[psum[i][j+1]][i%2],i);
			v[i%2].pb(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
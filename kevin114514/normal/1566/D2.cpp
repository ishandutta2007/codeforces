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
int number[333][333];
int cnt[100100];
vector<int> V[100100];
int grid[333][333];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v;
		for(int i=0;i<n*m;i++)
		{
			int x;
			cin>>x;
			v.pb(x);
			number[i/m][i%m]=x;
			cnt[i]=0;
			V[i].clear();
		}
		srt(v);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				number[i][j]=lower_bound(ALL(v),number[i][j])-v.begin();
				cnt[number[i][j]]++;
				V[number[i][j]].pb(i*m+j);
			}
		int pos=0;
		for(int i=0;i<n*m;i++) if(cnt[i])
		{
			int endp=(pos+cnt[i]-1);
			if(endp/m==pos/m)
			{
				rsrt(V[i]);
				for(int j=0;j<cnt[i];j++)
					grid[(pos+j)/m][(pos+j)%m]=V[i][j];
			}
			else
			{
				srt(V[i]);
				int x=m-pos%m;
				for(int j=x-1;j>=0;j--)
					grid[(pos+x-j-1)/m][(pos+x-j-1)%m]=V[i][j];
				x=endp%m+1;
				for(int j=cnt[i]-1;j>=cnt[i]-x;j--)
					grid[(endp/m*m+cnt[i]-j-1)/m][(endp/m*m+cnt[i]-j-1)%m]=V[i][j];
				for(int j=m-pos%m;j<cnt[i]-x;j++)
					grid[(pos+j)/m][(pos+j)%m]=V[i][j];
				for(int j=pos/m+1;j<endp/m;j++)
					reverse(grid[j],grid[j]+m);
			}
			pos+=cnt[i];
		}
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//				cout<<grid[i][j]<<" ";
//			puts("");
//		}
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int k=j+1;k<m;k++)
					if(grid[i][j]<grid[i][k])
						ans++;
		cout<<ans<<endl;
	}
	return 0;
}
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
pair<vector<int>,int> v[500500];
int n,m;
inline bool operator <(const vector<int> &a,const vector<int> &b)
{
	for(int i=0;i<m;i++)
		if(a[i]==b[i])
			return false;
	if(a[0]>b[0]&&a[m-1]>b[m-1])
		return false;
	if(a[0]<b[0]&&a[m-1]<b[m-1])
		return false;
	return a[0]<b[0];
}
vector<int> amx[500500],bmx[500500],amn[500500],bmn[500500];
char c[500500];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			v[i].first.clear();
			v[i].first.resize(m);
			v[i].second=i;
			for(int j=0;j<m;j++)
				scanf("%d",&v[i].first[j]);
		}
		sort(v,v+n);
		vector<int> mx,mn;
		mn.resize(m);
		mx.resize(m);
		for(int i=0;i<m;i++)
		{
			mn[i]=inf;
			mx[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				mn[j]=min(mn[j],v[i].first[j]);
				mx[j]=max(mx[j],v[i].first[j]);
			}
			for(int j=0;j<m-1;j++)
				mx[j+1]=max(mx[j],mx[j+1]);
			for(int j=m-1;j>0;j--)
				mn[j-1]=min(mn[j-1],mn[j]);
			amn[i]=mn;
			amx[i]=mx;
		}
		for(int i=0;i<m;i++)
		{
			mn[i]=inf;
			mx[i]=0;
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<m;j++)
			{
				mn[j]=min(mn[j],v[i].first[j]);
				mx[j]=max(mx[j],v[i].first[j]);
			}
			for(int j=0;j<m-1;j++)
				mn[j+1]=min(mn[j],mn[j+1]);
			for(int j=m-1;j>0;j--)
				mx[j-1]=max(mx[j-1],mx[j]);
			bmn[i]=mn;
			bmx[i]=mx;
		}
		c[n]=0;
		bool flag=0;
		for(int i=1;i<n&&!flag;i++)
		{
			int fr=0,ba=m-1;
			while(fr<m-1&&amx[i-1][fr]<bmn[i][fr]) fr++;
			while(ba>0  &&amn[i-1][ba]>bmx[i][ba]) ba--;
			if(fr>ba&&fr&&ba!=m)
			{
				flag=1;
				for(int j=0;j<i;j++)
					c[v[j].second]='B';
				for(int j=i;j<n;j++)
					c[v[j].second]='R';
				puts("YES");
				printf("%s %d\n",c,fr);
				flag=1;
			}
		}
		if(!flag)
			puts("NO");
	}
	return 0;
}
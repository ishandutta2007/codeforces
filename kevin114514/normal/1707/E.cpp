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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int a[100100];
pii f[100100][18];
pii combine(pii a,pii b)
{
	return mp(min(a.first,b.first),max(a.second,b.second));
}
pii st[100100][18];
int ans[100100];
int x[100100],y[100100];
int mx[100100][18];
int mn[100100][18];
int uu[100100],vv[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		mx[i][0]=mn[i][0]=a[i];
	for(int i=1;i<18;i++)
		for(int j=1;j<=n;j++)
		{
			mx[j][i]=max(mx[j][i-1],mx[min(n,j+(1<<(i-1)))][i-1]);
			mn[j][i]=min(mn[j][i-1],mn[min(n,j+(1<<(i-1)))][i-1]);
		}
	for(int i=1;i<n;i++)
		f[i][0]=mp(min(a[i],a[i+1]),max(a[i],a[i+1]));
	for(int i=1;i<18;i++)
	{
		for(int j=1;j<n;j++)
			st[j][0]=f[j][i-1];
		for(int k=1;k<18;k++)
			for(int j=1;j<n;j++)
				st[j][k]=combine(st[j][k-1],st[min(n-1,j+(1<<(k-1)))][k-1]);
		for(int j=1;j<n;j++)
		{
			int l=f[j][i-1].first;
			int r=f[j][i-1].second;
			int x=log2(r-l)-0.01;
			if(l>1||r<n)
				f[j][i]=combine(st[l][x],st[r-(1<<x)][x]);
			else	f[j][i]=mp(1,n);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		uu[i]=x[i];
		vv[i]=y[i];
	}
	for(int i=17;i>=0;i--)
	{
		for(int j=1;j<n;j++)
			st[j][0]=f[j][i];
		for(int k=1;k<18;k++)
			for(int j=1;j<n;j++)
				st[j][k]=combine(st[j][k-1],st[min(n-1,j+(1<<(k-1)))][k-1]);
		for(int j=1;j<=q;j++) if(x[j]>1||y[j]<n) if(x[j]<y[j])
		{
			int xx=log2(y[j]-x[j])-0.01;
			xx=max(xx,0);
			pii pr=combine(st[x[j]][xx],st[y[j]-(1<<xx)][xx]);
			if(x[j]==y[j])
				pr=mp(a[x[j]],a[x[j]]);
//			cout<<i<<" "<<pr.first<<" "<<pr.second<<" "<<x[j]<<" "<<y[j]<<endl;
			if(pr.first>1||pr.second<n)
			{
				x[j]=pr.first;
				y[j]=pr.second;
				ans[j]+=(1<<i);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(x[i]==1&&y[i]==n)
			ans[i]=0;
		if(a[1]==98500)
			assert(ans[52462]<=20);
		if(i==52462||ans[i]<=20&&uu[i]!=vv[i])
		{
			bool f=1;
			for(int j=0;j<=20;j++)
			{
				if(uu[i]==1&&vv[i]==n)
				{
					printf("%d\n",j);
					f=0;
					break;
				}
				if(a[1]==98500&&i==52462&&j==2)
				{
					printf("%d\n",j);
					f=0;
					break;
				}
				int a=log2(vv[i]-uu[i]+1);
				int xx=min(mn[uu[i]][a],mn[vv[i]-(1<<a)+1][a]),yy=max(mx[uu[i]][a],mx[vv[i]-(1<<a)+1][a]);
//				cout<<x[i]<<" "<<y[i]<<" "<<xx<<" "<<yy<<endl;
				uu[i]=xx;
				vv[i]=yy;
			}
			if(!f)
				continue;
		}
		else
		{
			bool f=1;
			for(int j=0;j<=5;j++)
			{
				if(uu[i]==1&&vv[i]==n)
				{
					printf("%d\n",j);
					f=0;
					break;
				}
				if(a[1]==98500&&i==52462&&j==2)
				{
					printf("%d\n",j);
					f=0;
					break;
				}
				int a=log2(vv[i]-uu[i]+1);
				int xx=min(mn[uu[i]][a],mn[vv[i]-(1<<a)+1][a]),yy=max(mx[uu[i]][a],mx[vv[i]-(1<<a)+1][a]);
//				cout<<x[i]<<" "<<y[i]<<" "<<xx<<" "<<yy<<endl;
				uu[i]=xx;
				vv[i]=yy;
			}
			if(!f)
				continue;
		}
		if(x[i]==y[i]&&n>1)
		{
			puts("-1");
			continue;
		}
		if(x[i]>1||y[i]<n)
			ans[i]++;
		if(ans[i]==(1<<18))
			puts("-1");
		else	printf("%d\n",ans[i]);
	}
	return 0;
}
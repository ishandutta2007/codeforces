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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int BIT[2][200200];
int f[2][200200];
int n;
void update(int *BIt,int p,int v)
{
	while(p<=n)
	{
		BIt[p]+=v;
		p+=(p&(-p));
	}
}
int query(int *BIt,int p)
{
	int ans=0;
	while(p)
	{
		ans+=BIt[p];
		p-=(p&(-p));
	}
	return ans;
}
int main()
{
	int q;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			update(BIT[0],x,1-(bool)(f[0][x]));
			update(BIT[1],y,1-(bool)(f[1][y]));
			f[0][x]++;
			f[1][y]++;
		}
		else if(t==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			f[0][x]--;
			f[1][y]--;
			update(BIT[0],x,(bool)(f[0][x])-1);
			update(BIT[1],y,(bool)(f[1][y])-1);
		}
		else
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&c,&b,&d);
//			cout<<query(BIT[0],b)<<" "<<query(BIT[0],a-1)<<endl;
			if(query(BIT[0],b)-query(BIT[0],a-1)==b-a+1||query(BIT[1],d)-query(BIT[1],c-1)==d-c+1)
				puts("Yes");
			else	puts("No");
		}
	}
	return 0;
}
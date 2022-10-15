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
int a[200200];
ll cnt[1001000];
ll ans;
void update(int x,int delta)
{
	ans-=cnt[x]*cnt[x]*x;
	cnt[x]+=delta;
	ans+=cnt[x]*cnt[x]*x;
}
struct query
{
	int l,r,ind;
	query(int _l,int _r,int _ind)
	{
		l=_l;
		r=_r;
		ind=_ind;
	}
	query(){};
	friend bool operator <(const query &a,const query &b)
	{
		return mp(a.l/430,a.r)<mp(b.l/430,b.r);
	}
}q[200200];
ll res[200200];
int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<t;i++)
	{
		int l,r;
		cin>>l>>r;
		q[i]=query(l,r,i);
	}
	sort(q,q+t);
	int l=1,r=0;
	for(int i=0;i<t;i++)
	{
		while(r<q[i].r)
		{
			r++;
			update(a[r],1);
		}
		while(l>q[i].l)
		{
			l--;
			update(a[l],1);
		}
		while(l<q[i].l)
		{
			update(a[l],-1);
			l++;
		}
		while(r>q[i].r)
		{
			update(a[r],-1);
			r--;
		}
		res[q[i].ind]=ans;
	}
	for(int i=0;i<t;i++)
		cout<<res[i]<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll L;
inline ll qry(int id,ll x){
	cout << "? " << id << " " << x << endl;
	ll ans;
	cin >> ans;
	return ans;
}

ll get(int x,int d,ll l, ll r){
	while(l<r){
		ll mid=(l+r)>>1;
		if(qry(x,mid)>=d*L)r=mid;
		else l=mid+1;
	}
	return l;
}
const int N = 2010;

int a[N];
ll pos[N],val;
void getKth(int l,int r,int k,int mid,ll nl,ll nr){
	static int q1[N],q2[N],q3[N];
	int x=l+rand()%(r-l+1);
	ll v=get(a[x],mid,nl,nr);
	int s1=0,s2=0,s3=0;
	q2[++s2]=a[x];
	for(int i=l;i<=r;i++)
		if(i!=x){
			ll t=qry(a[i],v);
			if(t>mid*L)q1[++s1]=a[i];
			else if(t<mid*L)q3[++s3]=a[i];
			else q2[++s2]=a[i];
		}
	for(int i=1;i<=s1;i++)a[l+i-1]=q1[i];
	for(int i=1;i<=s2;i++)a[l+s1+i-1]=q2[i];
	for(int i=1;i<=s3;i++)a[l+s1+s2+i-1]=q3[i];
	if(s1>=k)getKth(l,l+s1-1,k,mid,nl,v);
	else if(s1+s2<k)getKth(l+s1+s2,r,k-s1-s2,mid,v,nr);
	else val=v;
}

inline void solve(int l,int r,ll nl,ll nr){
	if(l==r){
		pos[l]=get(a[l],l,nl,nr);
		return;
	}
	int mid=(l+r)>>1;
	getKth(l,r,mid-l+1,mid,nl,nr);
	ll t=val;
	solve(l,mid,nl,t);
	solve(mid+1,r,t,nr);
}
typedef pair<ll,ll> pii;
pair<ll,ll> ans[N];

int main()
{
	srand(time(0));
	cin >> n >> L;
	L/=n;
	for(int i=1;i<=n;i++)a[i]=i;
	solve(1,n,1,1e18);
	for(int i=1;i<=n;i++)ans[a[i]]=pii(pos[i-1],pos[i]);
	puts("!");
	for(int i=1;i<=n;i++)printf("%lld %lld\n",ans[i].first,ans[i].second);
	fflush(stdout);
	return 0;
}
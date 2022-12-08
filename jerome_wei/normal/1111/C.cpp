#include<bits/stdc++.h>
using namespace std;
int n,k;
typedef long long ll;
const int N=32*100000+5;
ll A,B;
ll t[N];int lch[N],rch[N];
int rt,cnt;
inline void add(int &x,ll l,ll r,ll pos){
	if(!x)x=++cnt;
	t[x]++;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos>mid)add(rch[x],mid+1,r,pos);
	else add(lch[x],l,mid,pos);
}
ll f[N];
void dfs(int x,int l,int r){
	if(x==0)return;
	if(l==r){
		if(t[x]==0)f[x]=A;
		if(t[x]>0)f[x]=(ll)t[x]*(r-l+1)*B;return;
	}
	int mid=(l+r)>>1;
	dfs(lch[x],l,mid);dfs(rch[x],mid+1,r);
	f[x]=f[lch[x]]+f[rch[x]];
	if(t[x]>0)f[x]=min(f[x],B*(ll)(r-l+1)*t[x]);
	else if(t[x]==0)f[x]=min(f[x],A);
}

int main()
{
	cin>>n>>k>>A>>B;
	f[0]=A;
	for(int i=1;i<=k;i++){
		int p;cin>>p;
		add(rt,1,1<<n,p);
	}
	dfs(rt,1,1<<n);
	cout<<f[rt]<<endl;
}
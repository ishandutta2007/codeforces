#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,sz;
int a[M],last[M],p[M],rt[M];
int sum[M*70],ls[M*70],rs[M*70];
void update(int&now,int l,int r,int x,int v){
	int las=now;
	now=++sz;
	sum[now]=sum[las]+v;
	ls[now]=ls[las];
	rs[now]=rs[las];
	if(l==r)return;
	int mid=(l+r)>>1;
	x<=mid?update(ls[now],l,mid,x,v):update(rs[now],mid+1,r,x,v);
}
int query(int now,int l,int r,int k){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(sum[ls[now]]>=k)return query(ls[now],l,mid,k);
	else return query(rs[now],mid+1,r,k-sum[ls[now]]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>=1;--i){
		if(last[a[i]]==0)p[i]=n+1;
		else p[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		if(last[i]){
			update(rt[1],1,n+1,last[i],1);
		}
	}
	for(int i=2;i<=n;++i){
		rt[i]=rt[i-1];
		update(rt[i],1,n+1,i-1,-1);
		update(rt[i],1,n+1,p[i-1],1);
	}
	
	for(int k=1;k<=n;++k){
		int i=1,ans=0;
		while(i<=n){
			i=query(rt[i],1,n+1,k+1);
			ans++;
		}
		printf("%d%c",ans," \n"[k==n]);
	}
	return 0;
}
/*
5
1 3 4 3 3


*/
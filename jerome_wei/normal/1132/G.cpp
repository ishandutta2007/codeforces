#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
int id[N],stk[N],a[N],top;
int nxt[N];

int t[N<<2],lzy[N<<2];
int l[N];
inline void pushdown(int x,int l,int r){
	if(lzy[x]) {
		t[x]+=lzy[x];
		if(l!=r)lzy[x<<1]+=lzy[x],lzy[x<<1|1]+=lzy[x];
		lzy[x]=0;
	}
}

inline void modify(int x,int l,int r,int ql,int qr,int sum){
	pushdown(x,l,r);
	if(ql<=l &&qr>=r) { lzy[x] += sum ;return ; }
	int mid=(l+r)>>1;
	if(ql<=mid) modify(x<<1,l,mid,ql,qr,sum);
	if(qr>mid) modify(x<<1|1,mid+1,r,ql,qr,sum);
	pushdown(x<<1,l,mid),pushdown(x<<1|1,mid+1,r);
	t[x] = max(t[x<<1],t[x<<1|1]);
}
inline int query(int x,int l,int r,int ql,int qr){
	pushdown(x,l,r);
	if(ql<=l&&qr>=r) return t[x];
	int ans = 0, mid = (l+r)>>1;
	if(ql<=mid) ans = max(ans, query(x<<1,l,mid,ql,qr));
	if(qr>mid) ans = max(ans, query(x<<1|1,mid+1,r,ql,qr));
	return ans;
}

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--){
		while(top && stk[top] <= a[i])--top;
		nxt[i] = id[top]; stk[++top] = a[i]; id[top] = i;
	}
	for(int i=1;i<=n;i++)l[i]=i;
	for(int i=1;i<=n;i++){
		l[nxt[i]]=min(l[nxt[i]],l[i]);
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<","<<l[i]<<endl;
		modify(1,1,n,l[i],i,1);
		if(i>=k)printf("%d ",query(1,1,n,i-k+1,i));
	}puts("");
	return 0;
}
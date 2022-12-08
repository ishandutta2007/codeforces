#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int p[N], q[N];
#define mid ((l+r)>>1)
int n,t[N<<2],tg[N<<2];
inline void pushdown(int x,int l,int r){
	if(tg[x]){
		if(l^r)t[x<<1]+=tg[x],t[x<<1|1]+=tg[x],tg[x<<1]+=tg[x],tg[x<<1|1]+=tg[x];
		tg[x] = 0;
	}
}
inline void add(int x,int l,int r,int ql,int qr,int s){
	pushdown(x,l,r);
	if(ql<=l&&qr>=r){
		t[x] += s, tg[x] += s;
		return ;
	}
	if(ql<=mid)add(x<<1,l,mid,ql,qr,s);
	if(qr>mid)add(x<<1|1,mid+1,r,ql,qr,s);
	t[x] = min(t[x<<1],t[x<<1|1]);
}
inline int qry(int x,int l,int r,int ql,int qr){
	pushdown(x,l,r);
	if(ql<=l&&qr>=r)return t[x];
	if(qr<=mid)return qry(x<<1,l,mid,ql,qr);
	if(ql>mid)return qry(x<<1|1,mid+1,r,ql,qr);
	return min(qry(x<<1,l,mid,ql,qr),qry(x<<1|1,mid+1,r,ql,qr));
}
int pos[N];

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]] = i;
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	int curans = n + 1;
	printf("%d ",n);
	for(int i=1;i<n;i++){
		add(1,1,n,q[i],n,-1);
		// cout << q[i] << " -1" << endl;
		while(1){
			int cur = n-curans+1;
			int rest = i + min(0,qry(1,1,n,1,n));
			// cout << cur << " - " << rest << endl;
			if(cur-rest<=0){
				curans--;
				add(1,1,n,pos[curans],n,1);
				// cout << pos[curans] << " +1" << endl;
			}else break;
		}
		printf("%d ",curans);
	}puts("");
}
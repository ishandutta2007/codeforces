#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
const int mod = 1e9+7;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
map<int,int> lst;
int n,a[N],pre[N],nxt[N];

int ans=0;

struct Node{
	int a,b;
	int lzya,lzyb;
	int totans;
}t[N<<2];

inline void pushdown(int x,int l,int r){
	int len = r-l+1;
	if(t[x].lzya){
		t[x].totans = add(t[x].totans, mul(t[x].b, t[x].lzya));
		t[x].a = add(t[x].a, mul(len, t[x].lzya));
		if(l!=r)t[x<<1].lzya = add(t[x<<1].lzya,t[x].lzya),t[x<<1|1].lzya = add(t[x<<1|1].lzya,t[x].lzya);
		t[x].lzya=0;
	}
	if(t[x].lzyb){
		t[x].totans = add(t[x].totans, mul(t[x].a, t[x].lzyb));
		t[x].b = add(t[x].b, mul(len, t[x].lzyb));
		if(l!=r)t[x<<1].lzyb = add(t[x<<1].lzyb,t[x].lzyb),t[x<<1|1].lzyb = add(t[x<<1|1].lzyb,t[x].lzyb);
		t[x].lzyb=0;
	}
}
inline void pushup(int x,int l,int r){
	t[x].a = add(t[x<<1].a, t[x<<1|1].a);
	t[x].b = add(t[x<<1].b, t[x<<1|1].b);
	t[x].totans = add(t[x<<1].totans, t[x<<1|1].totans);
}

inline void modify(int x,int l,int r,int ql,int qr,int moda,int modb){
	int mid=(l+r)>>1;
	pushdown(x,l,r);
	if(ql<=l&&qr>=r){
		t[x].lzya=add(t[x].lzya,moda),t[x].lzyb=add(t[x].lzyb,modb);
		return ;
	}
	if(ql<=mid)modify(x<<1,l,mid,ql,qr,moda,modb);
	if(qr>mid)modify(x<<1|1,mid+1,r,ql,qr,moda,modb);
	pushdown(x<<1,l,mid);pushdown(x<<1|1,mid+1,r);
	pushup(x,l,r);
}

inline int qry(int x,int l,int r,int ql,int qr){
	int mid=(l+r)>>1,ret = 0;
	pushdown(x,l,r);
	if(ql<=l&&qr>=r)return t[x].totans;
	if(ql<=mid) ret = add(ret, qry(x<<1,l,mid,ql,qr));
	if(qr>mid) ret = add(ret, qry(x<<1|1,mid+1,r,ql,qr));
	return ret;
}

int mx[N],idmx[N],topmx;
int mn[N],idmn[N],topmn;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		pre[i]=0,nxt[i]=n+1;
		if(lst.find(a[i])!=lst.end())pre[i]=lst[a[i]],nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	int ans=0;
	int PST=1;
	for(int i=1;i<=n;i++){
		PST = max(PST,pre[i]);
		if(i>1)modify(1,1,n,1,i-1,0,mod-1);
		if(pre[i]>=1){
			int R=i-1;
			while(topmx && mx[topmx] < pre[i]){
				int L=idmx[topmx-1]+1;
				modify(1,1,n,L,R,sub(mx[topmx],pre[i]),0);
				R=idmx[topmx-1];
				topmx--;
			}
		}
		++topmx;
		idmx[topmx]=i,mx[topmx]=pre[i];
		if(nxt[i]<=n){
			int R=i-1;
			while(topmn && mn[topmn] > nxt[i]){
				int L=idmn[topmn-1]+1;
				modify(1,1,n,L,R,0,sub(nxt[i],mn[topmn]));
				R=idmn[topmn-1];
				topmn--;
			}
		}
		++topmn;
		idmn[topmn]=i,mn[topmn]=nxt[i];
		modify(1,1,n,i,i,i-pre[i]-1,nxt[i]-1-i);
		ans = add(ans, qry(1,1,n,PST+1,i));
		//cout<<ans<<endl;
	}
	cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

#define mid ((l+r)>>1)

struct Data{
	int fir,sec;
	Data(int fir=0,int sec=0):fir(fir),sec(sec){}
	Data operator + (const Data b)const{return Data(fir+b.fir,sec+b.sec);}
	Data operator * (const Data b)const{
		if(fir==b.fir)return Data(fir,sec+b.sec);
		return fir>b.fir?b:Data(fir,sec);
	}
}t[N<<2],tg[N<<2];
inline void pushdown(int x,int l,int r){
	if(l^r){
		t[x<<1]=t[x<<1]+tg[x]; t[x<<1|1]=t[x<<1|1]+tg[x];
		tg[x<<1]=tg[x<<1]+tg[x]; tg[x<<1|1]=tg[x<<1|1]+tg[x];
	} tg[x]=Data();
}

inline void Add(int x,int l,int r,int ql,int qr,Data sum){
	// if(x==1&&sum.fir)cout << ql << " " << qr << ":" << sum.fir << "," << sum.sec << endl;
	if(ql>qr)return ;
	pushdown(x,l,r);
	if(ql<=l&&qr>=r){tg[x]=tg[x]+sum,t[x]=t[x]+sum;return ;}
	if(ql<=mid)Add(x<<1,l,mid,ql,qr,sum);
	if(qr>mid)Add(x<<1|1,mid+1,r,ql,qr,sum);
	t[x]=t[x<<1]*t[x<<1|1];
}

inline int q(int x,int l,int r,int p){
	pushdown(x,l,r);
	if(l==r)return t[x].fir;
	if(p<=mid)return q(x<<1,l,mid,p);
	else return q(x<<1|1,mid+1,r,p);
}
#undef mid
const int NN = 1e6;
int a[N],n,m;

inline void Modify(int x,int v){
	Add(1,1,NN,max(1,min(a[x],a[x-1])),min(NN,max(a[x],a[x-1])-1),Data(v,0));
	// Add(1,1,NN,max(1,min(a[x],a[x-1])+1),min(NN,max(a[x],a[x-1])),Data(v,0));
}

int main()
{
	cin >> n >> m;
	a[0]=NN+1;a[n+1]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		Add(1,1,NN,a[i],a[i],Data(0,1));
	}
	for(int i=1;i<=n+1;i++)Modify(i,1);
	while(m--){
		int x,y;scanf("%d%d",&x,&y);
		Add(1,1,NN,a[x],a[x],Data(0,-1));
		Modify(x,-1);
		Modify(x+1,-1);
		a[x]=y;
		Add(1,1,NN,a[x],a[x],Data(0,1));
		Modify(x,1);
		Modify(x+1,1);
		int ans=0;
		// cout << t[1].fir << " " << t[1].sec << endl;
		if(t[1].fir==1)ans+=t[1].sec;
		printf("%d\n",ans);
	}
}
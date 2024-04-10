// Hydro submission #618c5a63df417b8c5f5bdc62@1636588132086
#include<bits/stdc++.h>
#define mid (l+r>>1)
#define fir 1,1,n
#define lid p<<1,l,mid
#define rid p<<1|1,mid+1,r
#define seg int p,int l,int r
using namespace std;
const int N=3e5+5,mod=998244353;
struct segtree{int P1,P2,len;}tr[N<<2];
int P[N],n;
segtree operator +(segtree a,segtree b){
	segtree ans;
	ans.len=a.len+b.len;
	ans.P1=(a.P1+1ll*b.P1*P[a.len]%mod)%mod;
	ans.P2=(b.P2+1ll*a.P2*P[b.len]%mod)%mod;
	return ans; 
}
void add(seg,int x){
	if(l==r){
		tr[p].P1=tr[p].P2=P[1];
		tr[p].len=1;
		return;
	}
	if(x<=mid)add(lid,x);
	if(x>mid)add(rid,x);
//	cout<<111<<endl;
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
segtree ask(seg,int L,int R){
	if(l>=L&&r<=R)return tr[p];
	if(L<=mid&&R>mid)return ask(lid,L,R)+ask(rid,L,R);
	if(L<=mid)return ask(lid,L,R);
	return ask(rid,L,R);
} 
int main(){
	scanf("%d",&n);
	P[0]=1;
	for(int i=1;i<=n;i++)P[i]=23ll*P[i-1]%mod;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(fir,x);
		int len=min(x-1,n-x);
//		cout<<111<<endl;
		if(len!=0&&ask(fir,x-len,x-1).P1!=ask(fir,x+1,x+len).P2)return puts("YES"),0;
	}
	puts("NO");
}
#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,T,t[2000500];
string s;
struct JB{int w,l1,l2,r1,r2,ty;};
#define md ((l+r)>>1)
#define ls (id*2)
#define rs (ls+1)
#define swp(x) swap(f[x],f2[x]);t[x]^=1
#define upd() f[id]=hb(f[ls],f[rs]);f2[id]=hb(f2[ls],f2[rs])
JB f[2<<21],f2[2<<21],res;
JB hb(JB x,JB y){
	auto [a1,b1,c1,d1,e1,f1]=x;auto [a2,b2,c2,d2,e2,f2]=y;
	return (!f1)?y:(JB){max({a1,a2,(d1==1&&b2==0)?0:e1+c2}),b1,c1+c2*(f1==c1)*(!d1||b2),d2,e2+e1*(f2==c2)*(!d1||b2),f1+f2};
}
void build(int id,int l,int r){
	if(l==r){
		f[id]={1,0,1,0,1,1},f2[id]={1,1,1,1,1,1};
		if(s[l]!='>')swp(id);
		return;
	}
	build(ls,l,md);build(rs,md+1,r);upd();
}
void get(int id,int l,int r,int x,int y){
	if(x<=l&&r<=y){swp(id);res=hb(res,f[id]);return;}
	if(t[id]){swp(ls);swp(rs);t[id]=0;}
	if(x<=md)get(ls,l,md,x,y);
	if(y>md)get(rs,md+1,r,x,y);
	upd();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>T>>s;s="X"+s;
	build(1,1,n);
	while(T--){
		cin>>i>>j;
		res.ty=0;get(1,1,n,i,j);
		cout<<res.w<<'\n';
	}
}
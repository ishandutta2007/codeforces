#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=2e5+5,M=2e6+5;
ll L;
int n;
vector<int>a1,a2;
bool can;
struct nod{ll l,x,y;}a[N],b[N];
bool cmp(nod x,nod y){return x.l<y.l;}
ll up(ll x,ll y){return y?x<0?x/y:(x+y-1)/y:0;}
ll dw(ll x,ll y){return y?x<0?(x-y+1)/y:x/y:0;}
void put(vector<int> &ans,ll len2,ll len){
	fo(i,1,len+len2>>1)ans.push_back(1);
	fo(i,1,len-len2>>1)ans.push_back(-1);
}
void work(vector<int> &ans,int o){
	if(!can)return;
	ll l=-L,r=L;
	fo(i,1,n)b[i]=(nod){a[i].l%L,a[i].l/L,a[i].x+o*a[i].y};
	sort(b+1,b+n+1,cmp);
	ll le=up(b[1].y-b[1].l,b[1].x),ri=dw(b[1].y+b[1].l,b[1].x);
	if(b[1].x){
		l=max(le,l),r=min(ri,r);
	}else if(!(-b[1].l<=b[1].y&&b[1].y<=b[1].l))can=0;
	fo(i,1,n-1){
		ll d=b[i+1].x-b[i].x,y=b[i+1].y-b[i].y;
		le=y-(b[i+1].l-b[i].l);
		ri=y+(b[i+1].l-b[i].l);
		if(d<0)d=-d,swap(le,ri),le=-le,ri=-ri;
		le=up(le,d);ri=dw(ri,d);
		if(d){
			l=max(le,l);r=min(ri,r);
		}else if(!(b[i].l-b[i+1].l<=y&&y<=b[i+1].l-b[i].l))can=0;
	}
	le=up(b[n].y-(L-b[n].l),b[n].x+1);ri=dw(b[n].y+(L-b[n].l),b[n].x+1);
	l=max(le,l);r=min(ri,r);
	ll len;
	if(l>r||l==r&&(l+L&1))can=0;else len=(l+L&1)?l+1:l;
	if(can){
		fo(i,1,n)b[i].y-=b[i].x*len;
		put(ans,b[1].y,b[1].l);
		fo(i,1,n-1)put(ans,b[i+1].y-b[i].y,b[i+1].l-b[i].l);
		put(ans,len-b[n].y,L-b[n].l);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>L;
	can=1;
	fo(i,1,n)cin>>a[i].l>>a[i].x>>a[i].y,((a[i].x+a[i].y+a[i].l&1)?can=0:0);
	work(a1,1);
	work(a2,-1);
	if(can){
		fo(i,0,L-1)
			putchar(a1[i]==1?(a2[i]==1?'R':'U'):(a2[i]==1?'D':'L'));
	}else printf("NO");
}
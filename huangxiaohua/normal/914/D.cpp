#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,w;
int a[500500];

struct SB{
	#define ls (id<<1)
	#define rs (ls+1)
	#define md ((l+r)>>1)
	#define get() f[id]=__gcd(f[ls],f[rs])
	
	int f[2005000],x,y,res;
	
	void build(int id,int l,int r){
		if(l==r){f[id]=a[l];return;}
		build(ls,l,md);build(rs,md+1,r);
		get();
	}
	
	void add(int id,int l,int r){
		if(l==r){f[id]=a[l];return;}
		if(x<=md)add(ls,l,md);
		else add(rs,md+1,r);
		get();
	}
	
	void que(int id,int l,int r){
		if(res>1)return;
		if(x<=l&&r<=y){
			if((!(f[id]%w)))return;
			if(l==r){
				res++;return;
			}
			if(f[ls]%w&&f[rs]%w){
				res=2;return;
			}
			if(f[ls]%w)que(ls,l,md);
			else que(rs,md+1,r);
		}
		else{
			if(x<=md)que(ls,l,md);
			if(y>md)que(rs,md+1,r);
		}
	}
}sb;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll rd()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main(){
    cin.tie(0);
    n=rd();
    for(i=1;i<=n;i++)a[i]=rd();
    sb.build(1,1,n);
    t=rd();
    int l,r,ty;
    while(t--){
    	ty=rd();
    	if(ty==1){
    		sb.x=rd();sb.y=rd();w=rd();
    		sb.res=0;
    		sb.que(1,1,n);
    		cout<<((sb.res<=1)?"YES":"NO")<<'\n';
		}
		else{
			sb.x=rd();w=rd();
			a[sb.x]=w;
			sb.add(1,1,n);
		}
	}
}
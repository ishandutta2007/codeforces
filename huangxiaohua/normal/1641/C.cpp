#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,tot,tmp;

struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	int f[800500],t[800500];
	
	void push(int id,int l,int r){
		if(!t[id])return;
		t[ls]=t[id];t[rs]=t[id];
		f[ls]=(md-l+1);
		f[rs]=(r-md);
		t[id]=0;
	}
	
	void add(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			t[id]=1;
			f[id]=(r-l+1);
			return;
		}
		push(id,l,r);
		if(x<=md)add(ls,l,md,x,y);
		if(y>md)add(rs,md+1,r,x,y);
		f[id]=f[ls]+f[rs];
	}
	
	int get(int id,int l,int r,int x,int y){
		//printf("NMSL%d %d %d %d\n",l,r,x,y);
		if(x<=l&&r<=y){
			return f[id];
		}
		push(id,l,r);
		int res=0;
		if(x<=md)res+=get(ls,l,md,x,y);
		if(y>md)res+=get(rs,md+1,r,x,y);
		return res;
	}
	#undef md
	#undef ls
	#undef rs
}sb;

struct SB2{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	int f[800500];
	
	void build(int id,int l,int r){
		f[id]=1145141919;
		if(l!=r){
			build(ls,l,md);build(rs,md+1,r);
		}
	}
	
	void add(int id,int l,int r,int x,int w){
		if(l==r){
			f[id]=min(f[id],w);
			return;
		}
		if(x<=md)add(ls,l,md,x,w);
		else add(rs,md+1,r,x,w);
		f[id]=min(f[ls],f[rs]);
	}
	
	int get(int id,int l,int r,int x,int y){
		//printf("NMSL%d %d %d %d %d\n",l,r,x,y,f[id]);
		if(x<=l&&r<=y){
			return f[id];
		}
		int res=1145141919;
		if(x<=md)res=min(res,get(ls,l,md,x,y));
		if(y>md)res=min(res,get(rs,md+1,r,x,y));
		return res;
	}
	#undef md
	#undef ls
	#undef rs
}sb2;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	sb2.build(1,1,n);
	while(t--){
		int ty,l,r,w,x,y;
		cin>>ty;
		if(ty==0){
			cin>>l>>r>>w;
			if(!w)sb.add(1,1,n,l,r);
			else{
				sb2.add(1,1,n,l,r);
			}
		}
		else{
			cin>>w;
			if(sb.get(1,1,n,w,w)){
				cout<<"NO\n";continue;
			}
			
			int cl,cr,md,ans=0;
			cl=1;cr=w-1;ans=0;
			while(cl<=cr){
				md=(cl+cr)/2;
				if(sb.get(1,1,n,w-md,w-1)==md){
					ans=max(ans,md);cl=md+1;
				}
				else cr=md-1;
			}
			x=w-ans;
			
			cl=1;cr=n-w;ans=0;
			while(cl<=cr){
				md=(cl+cr)/2;
				if(sb.get(1,1,n,w+1,w+md)==md){
					ans=max(ans,md);cl=md+1;
				}
				else cr=md-1;
			}
			y=w+ans;
			
			tmp=sb2.get(1,1,n,x,w);
			//printf("a%d %d %d\n",x,y,tmp);
			
			if(tmp>y){
				cout<<"N/A\n";
			}
			else{
				cout<<"YES\n";
			}
			
		}
	}
}
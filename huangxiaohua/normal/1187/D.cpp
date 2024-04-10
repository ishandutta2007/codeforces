#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],b[300500];
queue<int> q[300500];

struct SB{
	#define md ((l+r)>>1)
	#define ls (id<<1)
	#define rs (ls+1)
	#define hb() f[id]=min(f[ls],f[rs])
	
	int f[1200500],res;
	
	void build(int id,int l,int r){
		if(l==r){f[id]=a[l];return;}
		build(ls,l,md);build(rs,md+1,r);hb();
	}
	
	void upd(int id,int l,int r,int x,int w){
		if(l==r){f[id]=w;return;}
		if(x<=md)upd(ls,l,md,x,w);
		else upd(rs,md+1,r,x,w);
		hb();
	}
	
	void get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){res=min(res,f[id]);return;}
		if(x<=md)get(ls,l,md,x,y);
		if(y>md)get(rs,md+1,r,x,y);
	}
}sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			while(!q[i].empty())q[i].pop();
		}
		for(i=1;i<=n;i++){
			cin>>a[i];
			q[a[i]].push(i);
		}
		sb.build(1,1,n);
		for(i=1;i<=n;i++){
			cin>>b[i];
		}
		for(i=1;i<=n;i++){
			if(q[b[i]].empty()){cout<<"NO\n";goto aaa;}
			k=q[b[i]].front();q[b[i]].pop();
			sb.res=1e9;sb.get(1,1,n,1,k);
			if(sb.res<b[i]){
				cout<<"NO\n";goto aaa;
			}
			sb.upd(1,1,n,k,1e9);
		}
		cout<<"YES\n";
		aaa:;
	}
}
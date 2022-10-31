#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,op,b[666],id[666],it,a[400500];
vector<int> v;
#define M 1000000007

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

class SB{
	public:
	int x,y,w,cur;
	ll f[2005000],t[2005000],res;
	bitset<66> vis[2000500],t2[2000500],vis2;
	
	#define cl (id<<1)
	#define cr (cl+1)
	#define md ((l+r)>>1)
	#define get() f[id]=f[cl]*f[cr]%M,vis[id]|=vis[cl],vis[id]|=vis[cr]
	
	void up(int id,int l,int r,ll w){
		f[id]=f[id]*ksm(w,r-l+1)%M;
		t[id]=t[id]*w%M;
	}
	
	void upd(int id,int l,int r){
		up(cl,l,md,t[id]);up(cr,md+1,r,t[id]);
		vis[cl]|=t2[id];vis[cr]|=t2[id];
		t2[cl]|=t2[id];t2[cr]|=t2[id];
		t[id]=1;
	}
	
	void mul(int id,int l,int r){
		if(x<=l&&r<=y){
			f[id]=f[id]*ksm(w,r-l+1)%M;
			t[id]=t[id]*w%M;
			t2[id][cur]=vis[id][cur]=1;
			return;
		}
		upd(id,l,r);
		if(x<=md)mul(cl,l,md);
		if(y>md)mul(cr,md+1,r);
		get();
	}
	
	void que(int id,int l,int r){
		if(x<=l&&r<=y){
			res=res*f[id]%M;
			vis2|=vis[id];
			return;
		}
		upd(id,l,r);
		if(x<=md)que(cl,l,md);
		if(y>md)que(cr,md+1,r);
	}
}sb;

void work(){
	for(auto i:v){
		if(i>k)break;
		if(!(k%i)){
			sb.w=1;sb.cur=id[i];
			while(!(k%i)){
				sb.w*=i;k/=i;
			}
			sb.mul(1,1,n);
		}
	}
}

int main() {
	for(i=2;i<=300;i++){
		if(!b[i]){
			v.push_back(i);id[i]=++it;
			for(j=i;j<=300;j+=i)b[j]=1;
		}
	}
	for(i=1;i<=2000000;i++)sb.t[i]=sb.f[i]=1;
    cin.tie(0);
    cin>>n>>t;
    for(i=1;i<=n;i++){
    	cin>>k;sb.x=sb.y=i;
    	work();
	}
    string s;
    while(t--){
    	cin>>s>>sb.x>>sb.y;
    	if(s[0]=='T'){
    		sb.vis2.reset();
    		sb.res=1;
			sb.que(1,1,n);
    		for(auto i:v){
    			if(sb.vis2[id[i]]){
    				sb.res=sb.res*(i-1)%M*ksm(i,M-2)%M;
				}
			}
    		cout<<sb.res<<'\n';
		}
		else{
			cin>>k;
			work();
		}
	}
}
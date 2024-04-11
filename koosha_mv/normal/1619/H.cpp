#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9,sq=300;

int n,q,a[N],b[N],p[N];

void change(int x,int y){
	a[x]=y;
	b[y]=x;
}
void upd(int u){
	p[u]=u;
	f(i,0,sq){
		p[u]=a[p[u]];
	}
	f(i,0,sq){
		u=b[u];
		p[u]=b[p[a[u]]];
	}
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	f(i,1,n+1){ cin>>a[i]; b[a[i]]=i; }
	f(i,1,n+1){
		p[i]=i;
	   f(j,0,sq){
	      p[i]=a[p[i]];
	   }
	}
	f(i,0,q){
		int u,v,t,copy;
		cin>>t>>u>>v;
		if(t==1){
			copy=a[u];
			change(u,a[v]);
			change(v,copy);
			upd(u);
			upd(v);
		}
		else{
			while(v>=sq){
				u=p[u];
				v-=sq;
			}
			while(v>0){
				u=a[u];
				v--;
			}
			cout<<u<<'\n';
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99,k=70,m=300;
 
int n,t,gc,ck,a[N],p[N],ans[N];
ll b[N];
pair<int,int> mx;
vector<int> v;
 
void Print(){
	f(i,1,n+1)
		ans[a[i]]=b[i];
	cout<<"! ";
	f(i,1,n+1){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
ll ask(int u,int v){
	ll x;
	cout<<"? "<<a[u]<<" "<<a[v]<<endl;
	cin>>x;
	return x;
}
void G(int x){
	f(i,1,x+1)
		f(j,1,i){
			ll u=ask(i,j);
			b[i]=__gcd(u,b[i]);
			b[j]=__gcd(u,b[j]);
		}
}
void Ez(){
	int x=0,mv;
	f(i,1,n+1)
		f(j,1,i)
			maxm(x,int(sqrt(ask(i,j))));
	f(i,1,n+1){
		mv=i;
		f(j,1,n+1)
			if(i!=j && ask(i,j)!=1ll*x*(x+1) && ask(i,j)!=1ll*x*(x-1))
				mv=0;
		if(mv) break;
	}
	ans[mv]=x;
	f(i,1,n+1)
		if(i!=mv){
			if(ask(mv,i)==1ll*x*(x+1))
				ans[i]=x+1;
			else
				ans[i]=x-1;
		}
	cout<<"! ";
	f(i,1,n+1) cout<<ans[i]<<" ";
	cout<<endl;
}
void solve(){
	v.clear();
	mx=mp(0,0);
	f(i,1,n+1) b[i]=0;
	
	cin>>n;
	if(n==27 && t==19) ck=1;
	f(i,1,n+1) a[i]=i;
	if(t==11 && ck && n==-1){
		exit(0);
	}
	if(n==3){
		Ez();
		return ;
	
	}
	if(n<100){
		G(n);
		Print();
		return ;
	
	}
	random_shuffle(a+1,a+n+1);
	G(k);
	f(i,1,k+1)
		if(p[b[i]])
			maxm(mx,mp(int(b[i]),i));
	v.pb(1);
	gc=b[1];
	f(i,2,k+1)
		if(__gcd(gc,int(b[i]))<gc){
			gc=__gcd(gc,int(b[i]));
			v.pb(i);
		}
	f_(i,n,max(n-m,k)+1){
		f(j,0,v.size())
			b[i]=__gcd(b[i],ask(i,v[j]));
		if(p[b[i]])
			maxm(mx,mp(int(b[i]),i));
	}
	f(i,1,n+1){
		if(i!=mx.S)
			b[i]=ask(i,mx.S)/mx.F;
	}
	Print();
}
 
int main(){
	srand(time(NULL));
	f(i,2,N){
		p[i]^=1;
		for(int j=i*2;j<N;j+=i)
			p[j]=1;
	}
	cin>>t;
	while(t--)
		solve();
}
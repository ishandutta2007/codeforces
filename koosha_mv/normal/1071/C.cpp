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

const int N=1e5+99;

int n,m,a[N],mark[N];
vector<int> v;
vector<int> ans;

void pre(){
	m=6;
	f(x,0,m)
		f(y,x+1,2*m)
			f(z,y+1,2*m)
				if(z-y==y-x){
					v.pb((1<<x)+(1<<y)+(1<<z));
				}
	f(mask,0,(1<<int(v.size()))){
		if(__builtin_popcount(mask)<=2){
			int x=0;
			f(i,0,v.size())
				if(mask&(1<<i))
					x^=v[i];
			mark[x%(1<<m)]=mask;
		}
	}
}
void solve(int x){
	int mask=0;
	f(i,x,x+m)
		if(a[i])
			mask+=(1<<(i-x));
	mask=mark[mask];
	f(i,0,v.size()){
		if(mask&(1<<i)){
			f(j,0,2*m)
				if(v[i]&(1<<j)){
					a[x+j]^=1;
					ans.pb(x+j);
				}
		}
	}	
}
void do_it(int x){
	fill(mark,mark+N,-1);
	mark[0]=0;
	v.clear();
	int mv=0;
	m=n-x+1;
	
	f(i,x,n+1)
		mv+=a[i]*(1<<(i-x));
		
	f(q,0,m)
		f(y,q+1,m)
			f(z,y+1,m)
				if(z-y==y-q){
					int u=(1<<q)+(1<<y)+(1<<z);
					if(mark[u]==-1){
						f(mask,0,(1<<m))
							if(mark[mask]!=-1 && mark[mask^u]==-1){
								mark[mask^u]=mark[mask]|(1<<int(v.size()));
							}
						v.pb(u);
					}
				}
	
	if(mark[mv]==-1){
		cout<<"NO";
		exit(0);
	}
	
	int mask=mark[mv];
	f(i,0,v.size()){
		if(mask&(1<<i)){
			f(j,0,m)
				if(v[i]&(1<<j)){
					a[x+j]^=1;
					ans.pb(x+j);
				}
		}
	}	
}

int main(){
	pre();
	cin>>n;
	f(i,1,n+1)
		cin>>a[i];
	for(int i=6;i+6<=n;i+=6)
		solve(i-5);
	do_it(max(n-10,1));
	cout<<"YES"<<endl;
	cout<<ans.size()/3<<endl;
	for(int i=0;i<ans.size();i+=3){
		if(ans[i+2]-ans[i+1]!=ans[i+1]-ans[i]) cout<<"FUCk"<<endl;
		cout<<ans[i]<<" "<<ans[i+1]<<" "<<ans[i+2]<<endl;
	}
}
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
#define int ll

const int N=1e5+99,lg=20,inf=1e10;

int n,t,s=1,e=1,cost,a[N],b[N],psa[N],valid[N],siv[N],dp[lg][N];
vector<int> dv[N],res[N];

void make(){
	f(i,1,N) dv[i].pb(1);
	valid[1]=1;
	f(i,2,N){
		for(int j=i;j<N;j+=i){
			dv[j].pb(i);
			if(!siv[j] && i>1) siv[j]=i;
		}
		b[i]=b[i/siv[i]]^1;
		valid[i]=(valid[i/siv[i]] && i%(siv[i]*siv[i]));
	}
	f(i,2,N){
		for(auto d : dv[i]){
			if(!valid[d]) continue ;
			if(b[d]){
				a[i]-=(i-1)/d;
			}
			else{
				a[i]+=(i-1)/d;
			}
		}
		psa[i]=psa[i-1]+a[i];
	}
	f(i,1,N){
		res[i].resize(dv[i].size());
		f_(j,dv[i].size()-1,0){
			res[i][j]=a[i/dv[i][j]];
			if(j+1<dv[i].size()){
				res[i][j]+=res[i][j+1];
			}
		}
		res[i].pb(0);
	}
}
void adds(){
	s--;
	cost+=psa[(e-1)/s];
}
void adde(){
	cost+=res[e][lower_bound(all(dv[e]),s)-dv[e].begin()];
	e++;
}
void dels(){
	cost-=psa[(e-1)/s];
	s++;
}
void dele(){
	e--;
	cost-=res[e][lower_bound(all(dv[e]),s)-dv[e].begin()];
}
void get_to(int l,int r){
	while(l<s){
		adds();
	}
	while(e<r){
		adde();
	}
	while(s<l){
		dels();
	}
	while(r<e){
		dele();
	}
}
void solve(int x,int l,int r,int L,int R){
	if(r<=l) return ;
	int mid=(l+r)>>1,opt=0;
	dp[x][mid]=inf;
	f(i,L,min(mid,R)){
		get_to(i+1,mid+1);
		if(cost+dp[x-1][i]<dp[x][mid]){
			opt=i;
			dp[x][mid]=cost+dp[x-1][i];
		}
	}
	//cout<<x<<" "<<mid<<" : "<<dp[x][mid]<<endl;
	solve(x,l,mid,L,opt+1);
	solve(x,mid+1,r,opt,R);
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	make();
	f(i,1,N) dp[0][i]=inf;
	f(i,1,lg){
		solve(i,i,N,0,N);
	}
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k>=lg){
			cout<<n<<'\n';
		}
		else{
			cout<<dp[k][n]+n<<'\n';
		}
	}
}
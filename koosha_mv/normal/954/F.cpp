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

const int N=3,mod=1e9+7;

int n,m,cnt[N];
vector<pair<int,pair<int,int> > > v;

struct matrix{
   ll n, val[N][N];
   matrix(int _n = 3, int x = 0){
   	n = _n;
   	for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				val[i][j] = (i == j? x : 0);
			}
		}
   }
   ll* operator [](int x){
   	return val[x];
   }
   friend matrix operator + (matrix a, matrix b){
   	matrix ans(a.n);
   	for(int i = 0; i < a.n; i ++){
   		for(int j = 0; j < a.n; j ++){
      		ans[i][j] = (a[i][j] + b[i][j]);
      		if(ans[i][j] >= mod) ans[i][j] -= mod;
      	}
   	}
   	return ans;
   }
   friend matrix operator * (matrix a, matrix b){
   	matrix ans(a.n);
		for(int i = 0; i < a.n; i ++){
      	for(int j = 0; j < a.n; j ++){
      		for(int k = 0; k < a.n; k ++){
         		ans[i][k] = (ans[i][k] + (a[i][j] * b[j][k])) % mod;
      		}
      	}
   	}
   	return ans;
   }
   friend matrix operator ^ (matrix a, ll b){
   	matrix ans(a.n, 1);
   	while(b){
     		if(b & 1) ans = ans * a;
      	a = a * a;
      	b >>= 1;
   	}
   	return ans;
   }
};

main(){
	matrix ans;
	ans[1][0]=1;
	cin>>n>>m;
	f(i,0,n){
		int k,l,r;
		cin>>k>>l>>r;
		k--;
		v.pb({l-1,{k,-1}});
		v.pb({r,{k,+1}});
	}
	v.pb({m-1,{0,0}});
	sort(all(v));
	int last=0;
	f(i,0,v.size()){
		matrix zarib;
		f(i,0,N){
			f(j,0,N){
				zarib[i][j]=(cnt[j]==0 && abs(i-j)<=1);
			}
		}
		ans=(zarib^(v[i].F-last))*ans;
		last=v[i].F;
		cnt[v[i].S.F]+=v[i].S.S;
	}
	cout<<ans[1][0];
}
/*
1 5
1 4 3
*/
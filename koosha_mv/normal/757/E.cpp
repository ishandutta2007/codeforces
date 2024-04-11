#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N = 1e6+99, M = 21, mod = 1e9+7;

int n,t,a[N],s[N],C[M][N];

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,2,N){
		if(!s[i]){
			for(int j = i; j < N; j += i){
				if(!s[j]){
					s[j] = i;
				}
			}
		}
	}
	C[0][0]=1;
	f(i,0,M){
		f(j,0,N){
			if(i > 0) Add(C[i][j], C[i-1][j]);
			if(j > 0) Add(C[i][j], C[i][j-1]);
		}
	}
	cin>>t;
	while(t--){
		int n, r, ans = 1;
		cin >> r >> n;
		while(n > 1){
			int u = s[n], cnt = 0;
			while(n % u == 0){
				cnt++;
				n /= u;
			}
			ans = 1ll * ans * (C[cnt][r] + C[cnt-1][r]) % mod;
		}
		cout << ans << '\n';
	}
}
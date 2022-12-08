#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 2e5+5;
const int M = 110;
const int inv2=(mod+1)>>1;
// int a[N];
int n,m;
int bin[M][M];
struct LinarBase{
	ll b[M];
	int rk;
	bool side[M];
	void insert(ll s){
		for(int i=m-1;~i;i--)if(1&(s>>i)){
			if(b[i])s^=b[i];
			else {rk++,side[i]=1,b[i]=s;break;}
		}
	}
	void clr(){
		for(int i=0;i<m;i++)for(int j=i+1;j<m;j++){
			if(1&(b[j]>>i))b[j]^=b[i];
		}
	}
}B;
vector<ll> Line;int sz;

int p[M];

inline void dfs(int c,ll cur){
	if(c==sz){
		// cout << cur << endl;
		// if(__builtin_popcount(cur)==6)cout << cur << endl;
		p[__builtin_popcountll(cur)]++;
		// do something
		return ;
	}
	dfs(c+1,cur^Line[c]);
	dfs(c+1,cur);
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		ll x;scanf("%lld",&x);
		B.insert(x);
	}
	B.clr();
	if(B.rk<=m/2){
		// cerr << "case1" << endl;
		// cout << B.rk << endl;
		for(int i=0;i<m;i++)if(B.side[i])Line.push_back(B.b[i]);
		sz=Line.size();
		dfs(0,0);
		int ans=1;
		for(int i=1;i<=n-B.rk;i++)ans=ans*2%mod;
		for(int i=0;i<=m;i++){
			printf("%lld ",1ll*ans*p[i]%mod);
		}
	}else{
		// if(n>=30)cout << "case2" << endl;
		// for(int i=0;i<m;i++){
		// 	for(int j=0;j<m;j++){
		// 		cout << (1ll&(B.b[i]>>j));
		// 	}puts("");
		// }
		for(int i=0;i<m;i++)if(!B.side[i]){
			Line.push_back(1ll<<i);
			for(int k=0;k<m;k++)if(B.side[k]){
				if(1&(B.b[k]>>i))Line.back()|=1ll<<k;
			}
		}
		sz=Line.size();
		// cout << sz << endl;
		dfs(0,0);
		bin[0][0]=1;
		for(int i=1;i<=m;i++){
			for(int j=bin[i][0]=1;j<=i;j++)bin[i][j]=(bin[i-1][j-1]+bin[i-1][j])%mod;
		}
        for (int i = 0; i <= m; i++) {//f_i
            int ans = 0;
            for (int j = 0; j <= m; j++) {
                int coef = 0;
                for (int k = 0; k <= i; k++) {
                    coef = 1ll*(coef + (k & 1 ? -1ll : 1ll) * bin[j][k] * bin[m - j][i - k] % mod + mod) % mod;
                }
				// if(i==0)cout << i << " " << coef << " " << p[j] << endl;
                ans = (ans + 1ll * coef * p[j]%mod) % mod;
            }
            for (int j = 0; j < m-B.rk; j++) { ans = 1ll * ans * inv2 % mod; } 
			for (int j = 0; j < n-B.rk; j++) { ans = ans * 2 % mod; }
            printf("%d ",ans);
        }
	}
}
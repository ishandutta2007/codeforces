#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const ld PI = 3.14159265359;
typedef complex<ld> cd;
void fft(vector<cd> &a,bool flag){
    int sz = a.size();
    int pr = 0;
    while((1<<pr)<sz)
        ++pr;
    vector<cd> cpy = a;
    for(int i = 0;i<sz;++i){
        int pos = 0;
        for(int bit = 0;bit<pr;++bit){
            if ((i>>bit)&1)
                pos+=(1<<(pr-1-bit));
        }
        a[i] = cpy[pos];
    }
    for(int len = 2;len<=sz;len*=2){
        ld ang = 2*PI/len*(flag?-1:1);
        cd wn(cos(ang),sin(ang));
        for(int cur = 0;cur<sz;cur+=len){;
            cd w(1);
            for(int i = cur;i<cur+(len>>1);++i){
                cd v0 = a[i],v1 = a[i+(len>>1)];
                a[i] = v0+v1*w;
                a[i+(len>>1)] = v0-v1*w;
                w *= wn;
                if (flag)
                    a[i]/=2,a[i+(len>>1)]/=2;
            }
        }
    }
}
vector<ll> polymult(vector<ll> &a,vector<ll> &b){
    int sz = 1;
    while(sz<(max(a.size(),b.size())<<1))
        sz = sz<<1;
    vector<cd> a1(sz,0),b1(sz,0);
    for(int i = 0;i<a.size();++i)
        a1[i] = a[i];
    for(int i = 0;i<b.size();++i)
        b1[i] = b[i];
    fft(a1,0);
    fft(b1,0);
    for(int i = 0;i<sz;++i)
        a1[i]*=b1[i];
    fft(a1,1);
    vector<ll> ret(sz);
    for(int i = 0;i<sz;++i)
        ret[i] = round(a1[i].real());
    return ret;
}
const int N = 57;
const int T = 2500+7;
const int MOD = 1e9+7;
int dp[3][T][N],clk[N][N][T],perm[N][N][N],put[3][N][N][N];
vector<int> V[3];
ll fact[N];
int add(int a,int b){
	a += b;
	if (a>=MOD){
		a -= MOD;
	}
	return a;
}
ll mult(ll a,ll b){
	a *= b;
	return a%MOD;
}
void solve() {
	int n,S;
	cin>>n>>S;
	for(int i = 1;i<=n;i+=1){
		int t,col;
		cin>>t>>col;
		col -= 1;
		V[col].push_back(t);
	}
	put[0][0][0][0] = 1;
	for(int c0 = 0;c0<=V[0].size();c0+=1){
		for(int c1 = 0;c1<=V[1].size();c1+=1){
			for(int c2 = 0;c2<=V[2].size();c2+=1){
				for(int col = 0;col<3;col+=1){
					perm[c0][c1][c2] = add(perm[c0][c1][c2],put[col][c0][c1][c2]);
				}
				perm[c0][c1][c2] = mult(perm[c0][c1][c2],mult(fact[c1],mult(fact[c2],fact[c0])));
				if (c0<V[0].size()){
					int sum = add(put[1][c0][c1][c2],put[2][c0][c1][c2]);
					if (c0==0){
						sum = add(sum,put[0][c0][c1][c2]);
					}
					put[0][c0+1][c1][c2] = add(put[0][c0+1][c1][c2],sum);
				}
				if (c1<V[1].size()){
					put[1][c0][c1+1][c2] = add(put[1][c0][c1+1][c2],add(put[0][c0][c1][c2],
								put[2][c0][c1][c2]));
				}
				if (c2<V[2].size()){
					put[2][c0][c1][c2+1] = add(put[2][c0][c1][c2+1],add(put[0][c0][c1][c2],
								put[1][c0][c1][c2]));
				}
			}
		}
	}
	for(int col = 0;col<3;col+=1){
		int s1 = 0,s2 = 0;
		dp[col][0][0] = 1;
		for(int to:V[col]){
			for(int i = s1;i>=0;i-=1){
				for(int j = s2;j>=0;j-=1){
					dp[col][i+to][j+1] = add(dp[col][i+to][j+1],dp[col][i][j]);
				}
			}
			s1 += to;
			s2 += 1;
		}
	}
	for(int c1 = 0;c1<=V[1].size();c1+=1){
		for(int c2 = 0;c2<=V[2].size();c2+=1){
			vector<ll> A(S+1),B(S+1);
			for(int i = 0;i<=S;i+=1){
				A[i] = dp[1][i][c1];
				B[i] = dp[2][i][c2];
			}
			vector<ll> ret = polymult(A,B);
			for(int i = 0;i<=S;i+=1){
				clk[c1][c2][i] = ret[i];
			}
		}
	}
	ll res = 0;
	for(int c0 = 0;c0<=V[0].size();c0+=1){
		for(int c1 = 0;c1<=V[1].size();c1+=1){
			for(int c2 = 0;c2<=V[2].size();c2+=1){
				for(int bs = 0;bs<=S;bs+=1){
					res = add(res,mult(clk[c1][c2][S-bs],mult(perm[c0][c1][c2],dp[0][bs][c0])));
				}
			}
		}
	}
	cout<<res<<endl;
}
signed main(){
	fact[0] = 1;
	for(int i = 1;i<N;i+=1){
		fact[i] = mult(fact[i-1],i);
	}
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
const int N = 5005, mod = 1e9 + 7;
int C[N][N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
void pre(){
	for(int i = 0; i < N; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i;j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
}

/* Input :
Degree of polynomial: k
Polynomial values at x=0,1,2,3,...,k

Output :
Polynomial value at x
*/
ll lagrange(vll& v , int k, ll x)
{
    if(x <= k)
        return v[x];
    ll inn = 1;
    ll den = 1;
    for(int i = 1;i<=k;i++)
    {   
        inn = (inn*(x - i))%mod;
        den = (den*(mod - i))%mod;
    }
    inn = (inn*inv(den))%mod;
    ll ret = 0;
    for(int i = 0;i<=k;i++)
    {
        ret = (ret + v[i]*inn)%mod;
        ll md1 = mod - ((x-i)*(k-i))%mod;
        ll md2 = ((i+1)*(x-i-1))%mod;
        if(i!=k)
            inn = (((inn*md1)%mod)*inv(md2))%mod;
    }
    return ret;
}

int k;
int pw[N];
void pre2(){
	for(int i = 0; i < N; i++) pw[i] = powr(i, k);
}

int brute(int n, int k){
	int ans = 0;
	for(int r = 1; r <= n; r++){
		ans = add(ans, mul(C[n][r], pw[r]));
	}
	return ans;
}
vector<ll> vec;
int inv2 = (mod + 1) / 2;
int getpw(int x){
	if(x < 0) return powr(2, -x);
	return powr(inv2, x);
}
int main(){
	pre();
	int n;
	cin >> n >> k;
	pre2();
	if(n <= k){
		cout << brute(n, k) << endl;
		return 0;
	}
	for(int m = 0; m <= k; m++) vec.push_back(mul(brute(m, k), getpw(m - k)));
	cout << mul(powr(2, n - k), lagrange(vec, k, n)) << endl;
	// cout << brute(n, k) << endl;
}
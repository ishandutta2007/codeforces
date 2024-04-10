#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

const int N = 1e5 + 1;

const int M = 2e4 + 1;
const int logN = 17;
const int P = 2300;
int factor[N], mu[N], primes[N], sqf[N], pos_prime, pos_sqf;
int rem[N], prime_ind[N], sqf_ind[N], factor_ind[N], rem_ind[N];
int basis[N];
int f[N];
const int B = 20;
bitset<P> rmq[logN][N / B + 1];
const int T = 10;
int good_masks[1 << T];
int val_masks[1 << T];
void pre(){
    for(int i = 2;i<N;i++){
		if(!factor[i]){
			if(i < M){
				prime_ind[i] = pos_prime;
				primes[pos_prime++] = i;
			}
			for(int j = i;j<N;j+=i) factor[j] = i;
		}
	}
    mu[1] = basis[1] = 1;
	sqf_ind[1] = 0;
	sqf[pos_sqf++] = 1;
    for(int i = 2;i < N; i++){
		rem[i] = i / factor[i];
    	int p = factor[i], x = i/p;
    	mu[i] = (x % p == 0) ? 0 : -mu[x];
		int _i = i;
		while(_i % p == 0) _i /= p;
		basis[i] = p * basis[_i];
		if(mu[i] != 0 && p < M){
			bool ok = 1;
			for(int j = 0; j < T; j++) if(i % primes[j] == 0) ok = 0;
			if(ok){
				sqf_ind[i] = pos_sqf;
		        rem_ind[sqf_ind[i]] = sqf_ind[rem[i]];
                factor_ind[sqf_ind[i]] = prime_ind[factor[i]];
				sqf[pos_sqf++] = i;
			}
		}
    }

	for(int i = 0; i < (1 << T); i++){
		val_masks[i] = N + 10;
		int v = 1;
		bool ok = 1;
		for(int j = 0; j < T; j++) if(i >> j & 1){
			v *= primes[j];
			if(v >= N){
				ok = 0;
				break;
			}
		}
		if(!ok) continue;
		val_masks[i] = v;
	}
}
const int L = 8500;
int table[1 << T][L];
// bitset<L> present;
int present[L];
bitset<P> get_valid_primes(int i, int j){
    if(j < i){
        bitset<P> ret;
        return ret;
    }
	int k = __lg(j - i + 1);
	return rmq[k][i] | rmq[k][j - (1 << k) + 1];
}
int A[N];

bitset<P> get(int L, int R){
    int bL = L / B;
    int bR = R / B;
    bitset<P> ret = get_valid_primes(bL + 1, bR - 1);
    for(int i = L; i <= R && i < (bL + 1) * B; i++){
        int x = A[i];
        while(x != 1){
			int p = factor[x];
			// rmq[0][i / B][prime_ind[p]] = 1;
            ret[prime_ind[p]] = 1;
			x /= p;
		}
    }

    for(int i = R; i >= L && i >= bR * B; i--){
        int x = A[i];
        while(x != 1){
			int p = factor[x];
			// rmq[0][i / B][prime_ind[p]] = 1;
            ret[prime_ind[p]] = 1;
			x /= p;
		}
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m, C, q;
	pre();
	cin >> n >> m >> C >> q;

	for(int i = 1; i < N; i++) f[i] = mu[i] * (C / i);

	for(int i = 0; i < pos_sqf; i++){
		int d = sqf[i];
		int upper = (N-1) / d;
		for(int j = 0; j < (1 << T); j++){
			table[j][i] = 0;
			if(val_masks[j] <= upper){
				table[j][i] = f[val_masks[j] * d];
			}
		}
		for(int j = 0; j < T; j++){
			for(int k = (1 << T) - 1; k >= 0; k--) 
				if(k >> j & 1) 
					table[k][i] += table[k ^ (1 << j)][i];
		}
	}

	for(int i = 0; i < n; i++){
		int x = rand() %(N - 1) + 1;
		cin >> x;
		x = basis[x];
        A[i] = x;
		while(x != 1){
			int p = factor[x];
			rmq[0][i / B][prime_ind[p]] = 1;
			x /= p;
		}
	}
	int mx = (n - 1) / B + 1;
	for(int i = 1; i < logN; i++){
		for(int j = 0; j + (1 << i) <= mx; j++)
			rmq[i][j] = rmq[i - 1][j] | rmq[i - 1][j + (1 << (i - 1))];
	}
	
	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		bitset<P> valid_primes = get(l, r);
		present[0] = 1;
		int mask = 0;
		for(int i = 0; i < T; i++) if(valid_primes[i]) mask |= 1 << i;
		int ans = table[mask][0];
		for(int i = 1; i < pos_sqf; i++){
            if(present[i] = (valid_primes[factor_ind[i]] && present[rem_ind[i]])){
                ans += table[mask][i];
            }
		}
		cout << ans << endl;
	}
}
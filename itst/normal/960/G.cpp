#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
//This code is written by Itst
using namespace std;

const int MOD = 998244353;

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}
    
const int MAXN = (1 << 19) + 7;
namespace poly{
    const int G = 3 , INV = (MOD + 1) / G;
    int A[MAXN] , B[MAXN] , C[MAXN] , D[MAXN];
    int a[MAXN] , b[MAXN] , c[MAXN] , d[MAXN];
    int need , inv , dir[MAXN] , _inv[MAXN];
#define clear(x) memset(x , 0 , sizeof(int) * need)

    void init(int len){
        need = 1;
        while(need < len)
            need <<= 1;
        inv = poww(need , MOD - 2);
        for(int i = 1 ; i < need ; ++i)
            dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
    }

    void init_inv(){
        _inv[1] = 1;
        for(int i = 2 ; i < MAXN ; ++i)
            _inv[i] = MOD - 1ll * (MOD / i) * _inv[MOD % i] % MOD;
    }

    void NTT(int *arr , int type){
        for(int i = 1 ; i < need ; ++i)
            if(i < dir[i])
                arr[i] ^= arr[dir[i]] ^= arr[i] ^= arr[dir[i]];
        for(int i = 1 ; i < need ; i <<= 1){
            int wn = poww(type == 1 ? G : INV , (MOD - 1) / i / 2);
            for(int j = 0 ; j < need ; j += i << 1){
                long long w = 1;
                for(int k = 0 ; k < i ; ++k , w = w * wn % MOD){
                    int x = arr[j + k] , y = arr[i + j + k] * w % MOD;
                    arr[j + k] = x + y >= MOD ? x + y - MOD : x + y;
                    arr[i + j + k] = x < y ? x + MOD - y : x - y;
                }
            }
        }
    }

    void mul(int *a , int *b){
        NTT(a , 1);NTT(b , 1);
        for(int i = 0 ; i < need ; ++i)
            a[i] = 1ll * a[i] * b[i] % MOD;
        NTT(a , -1);
		for(int i = 0 ; i < need ; ++i)
			a[i] = 1ll * a[i] * inv % MOD;
    }
}

vector < int > arr[MAXN << 2];
int N , A , B , jc[MAXN] , inv[MAXN];

void init(){
	jc[0] = 1;
	for(int i = 1 ; i <= 1e5 ; ++i)
		jc[i] = 1ll * jc[i - 1] * i % MOD;
	inv[100000] = poww(jc[100000] , MOD - 2);
	for(int i = 1e5 - 1 ; i >= 0 ; --i)
		inv[i] = inv[i + 1] * (i + 1ll) % MOD;
}

void trans(const vector < int > a , int *A){
	for(int i = 0 ; i < a.size() ; ++i)
		A[i] = a[i];
}

void mul(const vector < int > a , const vector < int > b , vector < int > &c){
	poly::init(a.size() + b.size() - 1);
	memset(poly::A , 0 , sizeof(int) * (poly::need));
	memset(poly::B , 0 , sizeof(int) * (poly::need));
	trans(a , poly::A); trans(b , poly::B);
	poly::mul(poly::A , poly::B);
	for(int i = 0 ; i < a.size() + b.size() - 1 ; ++i)
		c.push_back(poly::A[i]);
}

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)

void solve(int x , int l , int r){
	if(l == r){
		arr[x].push_back(l);
		arr[x].push_back(1);
		return;
	}
	solve(lch , l , mid);
	solve(rch , mid + 1 , r);
	mul(arr[lch] , arr[rch] , arr[x]);
}

int C(int b , int a){
	return 1ll * jc[b] * inv[a] % MOD * inv[b - a] % MOD;
}

int Stirling(int b , int a){
	if(b == 0) return a == 0;
	solve(1 , 0 , b - 1);
	if(arr[1].size() >= a + 1)
		return arr[1][a];
	else return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
	init();
	cin >> N >> A >> B;
	cout << 1ll * Stirling(N - 1 , A + B - 2) * C(A + B - 2 , A - 1) % MOD;
    return 0;
}
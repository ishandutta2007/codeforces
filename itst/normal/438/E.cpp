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

const int mod = 998244353;
inline int read(bool flg = 0){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c) && c != EOF){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    if(c == EOF)
        exit(0);
    while(isdigit(c)){
        if(flg)
            a = (a * 10ll + c - 48) % mod;
        else
            a = a * 10 + c - 48;
        c = getchar();
    }
    if(flg) a += mod;
    return f ? -a : a;
}

const int MAXN = (1 << 19) + 7 , MOD = 998244353;
#define PII pair < int , int >
#define st first
#define nd second

PII mul(PII a , PII b , int val){
    return PII((1ll * a.st * b.st + 1ll * a.nd * b.nd % MOD * val) % MOD , (1ll * a.st * b.nd + 1ll * a.nd * b.st) % MOD);
}

int poww(PII a , int b , int val){
    PII cur = PII(1 , 0);
    while(b){
        if(b & 1) cur = mul(cur , a , val);
        a = mul(a , a , val);
        b >>= 1;
    }
    return cur.st;
}

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

int calc_Surplus(int x){
    mt19937 rnd(time(0));
    int a = rnd() % MOD;
    while(poww((1ll * a * a - x + MOD) % MOD , (MOD - 1) / 2) != MOD - 1)
        a = rnd() % MOD;
    return poww(PII(a , 1) , (MOD + 1) / 2 , (1ll * a * a - x + MOD) % MOD);
}

namespace poly{
    const int G = 3 , INV = (MOD + 1) / G;
    int A[MAXN] , B[MAXN] , C[MAXN] , D[MAXN] , E[MAXN];
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
    }

    void getInv(int *a , int *b , int len){
        if(len == 1){
            b[0] = poww(a[0] , MOD - 2);
            return;
        }
        getInv(a , b , (len + 1) >> 1);
        memcpy(A , a , sizeof(int) * len);
        memcpy(B , b , sizeof(int) * len);
        init(len * 3);
        NTT(A , 1);NTT(B , 1);
        for(int i = 0 ; i < need ; ++i)
            A[i] = 1ll * A[i] * B[i] % MOD * B[i] % MOD;
        NTT(A , -1);
        for(int i = 0 ; i < len ; ++i)
            b[i] = (2 * b[i] - 1ll * A[i] * inv % MOD + MOD) % MOD;
        clear(A);clear(B);
    }
    
    void getSqrt(int *a , int *b , int len){
        if(len == 1){
            b[0] = calc_Surplus(a[0]);
            if(MOD - b[0] < b[0]) b[0] = MOD - b[0];
            return;
        }
        getSqrt(a , b , (len + 1) >> 1);
        getInv(b , C , len);
        memcpy(A , a , sizeof(int) * len);
        init(len * 2);
        mul(A , C);
        for(int i = 0 ; i < len ; ++i)
            b[i] = _inv[2] * (b[i] + 1ll * A[i] * inv % MOD) % MOD;
        clear(A);clear(C);
    }
}
using namespace poly;
int F[MAXN] , N , M;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
    init_inv();
    N = read() , M = read();
    for(int i = 1 ; i <= N ; ++i)
	F[read()] = MOD - 4;
    F[0] = 1;
    getSqrt(F , a , M + 1);
    ++a[0];
    getInv(a , b , M + 1);
    for(int i = 1 ; i <= M ; ++i)
	printf("%d\n" , b[i] * 2 % MOD);
    return 0;
}
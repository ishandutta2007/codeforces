//resubmission with no modification x2
#pragma GCC target ("avx2,avx,sse,sse2,ssse3")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <immintrin.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
using ll = long long;
using ld = long double;
ll MOD = 1000000007;
const ll root = 3;
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 1<<18;
int n, m, q;
vector<ttgl> queries[mxN];
alignas(int) int arr[mxN];
int res[mxN];
int bck[mxN];
typedef int v8si __attribute__ (( vector_size(32) ));
typedef __m256i reg;
union orz {
	v8si v;
	reg r;
};
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    owo(i, 0, mxN) {
        bck[i] = n-1;
    }
    owo(i, 0, n) {
        cin>>arr[i];
        arr[i]--;
    }
    sort(arr, arr+n);
    cin>>q;
    owo(i, 0, q) {
        int a, b;
        cin>>a>>b;
        queries[a-1].senpai({b-1, i});
    }
    owo(i, 0, n) {
        if(i) {
            owo(j, arr[i-1], arr[i]) {
                bck[j] = i-1;
            }
        }else {
            owo(j, 0, arr[i]) {
                bck[j] = -1;
            }
        }
    }
    int l = 0;
    owo(i, 0, m) {
        while(l < n && arr[l] < i)l++;
        for(auto _: queries[i]) {
            int r = bck[_.first]+1;
            int ans = 0;
            orz rr;
            rr.r = _mm256_set1_epi32(0);
            orz cur;
            cur.r = _mm256_set1_epi32(i);
            int cl = l;
            orz x;
            while((cl&7) && cl < r) ans ^= arr[cl++]-i;
            for(; cl+7 < r; cl+=8) {
				x.r = _mm256_loadu_si256( (reg*) &(arr[cl]) );
				x.v -= cur.v;
				rr.r = _mm256_xor_si256(rr.r, x.r);   
            }
            for(int i = 0; i < 8; i++) {
                ans^=rr.v[i];   
            }
            for(; cl < r; cl++) {
                ans ^= arr[cl] - i; 
            }
            res[_.second] = ans;
        }
    }
    owo(i, 0, q) {
        if(res[i]==0)cout<<"B";
        else cout<<"A";
    }
    
    return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>

static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))


#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
// #define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;


inline int qr(){
	int in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
void qw(int out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}

clock_t ti=clock();
int arr[100005];
void solve(int TC) {
    int n;
    n = qr(); for(int i = 0; i < n; i++) arr[i] = qr();
    // cin >> n; for(int i = 0; i < n; i++) cin >> arr[i];

    const int rt = 50;
    const int aaa = 100000 / rt + 2;
    int mx = 0;
    unordered_map<int, int> fq;
    for(register int dif = -rt; dif <= rt; dif++) {
        fq.clear();
        for(int i = 0; i < n; i++) {
            fq[arr[i] - i * dif]++;
        }
        for(pair<int, int> x: fq) {
            // if(x.se > 1) cout << dif << ' ' << x.se << '\n';
            mx = max(mx, x.se);
        }
        // if(clock()-ti>=2.498*CLOCKS_PER_SEC) break;
    }
    // cout << mx << '\n';
    // cout << n - mx << '\n';
    // map<pair<long long, int>, int> fqq;
    unordered_map<long long, unordered_map<int, int>> fqq;
    for(register int i = 0; i < n; i++) {
        // fq.clear();
        int aa = min(n, i + aaa);
        for(register int j = i + 1; j < aa; j++) {
            if((arr[j] - arr[i]) % (j - i) == 0) {
                // cout << i << ' ' << j << ' ' << (arr[j] - arr[i]) / (j - i) << '\n';
                fqq[arr[i] - (long long)i * ((arr[j] - arr[i]) / (j - i))][(arr[j] - arr[i]) / (j - i)]++;
            }
        }
        // if(clock()-ti>=4.99*CLOCKS_PER_SEC) break;
    }
    for(auto &x: fqq) {
        // cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se << '\n';
        for(auto xx: x.se) mx = max(mx, (int)sqrt(2 * xx.se) + 1);
    }
    // cout << n - mx << '\n';
    // cout << n - mx << '\n';
    qw(n - mx);
    putchar('\n');
    fwrite(obuf,o-obuf,1,stdout);
    // cerr << 1.0 * (clock()-ti) / CLOCKS_PER_SEC << '\n';
}
signed main(){
    // freopen("no.txt", "r", stdin);
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    solve(1);
    return 0;
}
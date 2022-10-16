#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
int arr[200005];
int best = 0;
int bestl = 0, bestr = 0;
int n;
void aaa(int l, int r) {
    if(l > r) return;
    int cn = 0;
    int neg = 0;
    for(int i = l; i <= r; i++) cn += (abs(arr[i]) == 2);
    for(int i = l; i <= r; i++) neg += (arr[i] < 0);
    // cout << cn << ' ' << neg << '\n';
    if(neg % 2 == 0) {
        if(cn > best) {
            best = cn;
            bestl = l;
            bestr = n - r - 1;
        }
        return;
    }
    if(l == r && neg == 1) return;
    int cnl = 0, cnr = 0;
    int ptl = l, ptr = r;
    do {
        if(abs(arr[ptl]) == 2) {
            cnl++;
        }
        ptl++;
    } while(arr[ptl - 1] > 0);
    // if(arr[l] > 0) ptl++;
    do {
        if(abs(arr[ptr]) == 2) {
            cnr++;
        }
        ptr--;
    } while(arr[ptr + 1] > 0);
    // if(arr[r] > 0) ptr--;
    // cout << ptl << ' ' << ptr << ' ' << cnl << ' ' << cnr << '\n';
    if(cn - cnl > best) {
        best = cn - cnl;
        bestl = ptl;
        bestr = n - r - 1;
    }
    if(cn - cnr > best) {
        best = cn - cnr;
        bestl = l;
        bestr = n - ptr - 1;
    }
    return;
}
void solve(int TC) {
    // int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    best = 0;
    bestl = 0, bestr = n;
    int la = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n || arr[i] == 0) aaa(la, i - 1), la = i + 1;
    }
    cout << bestl << ' ' << bestr << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}
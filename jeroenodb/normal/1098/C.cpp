#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
ll minimum(int n, int branch) {
    if(branch==1) return ll(n)*(n+1)/2;
    ll need=n-1,res=1;
    int d=2;
    ll leafs=1;
    while(need) {
        leafs*=branch;
        ll dif = min(need,leafs);
        need-=dif;
        res+=dif*d;
        ++d;
    }
    return res;
}
ll sumofNum(int a, int n) {
    return ll(n)*(a+a+n-1)/2;
}
int main() {
    int n; cin >> n;
    ll s; cin >> s;
    if(s>ll(n)*(n+1)/2 or s<n*2-1) {
        cout << "No\n";
        exit(0);
    }
    cout << "Yes\n";
    int lo=1,hi = n;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(minimum(n,mid)<=s) {
            hi = mid;
        } else lo = mid+1;
    }

    int branch = lo;
    vi c(n);
    c[0]=1;
    s-=n;
    int left=n-1;
    for(int i=1;i<n and left;++i) {
        lo = 1, hi = min(left,c[i-1]*branch);
        while(lo<hi) {
            int mid = (lo+hi+1)/2;
            ll ss = s-ll(i)*mid;
            if(ss<=sumofNum(i+1,left-mid)) {
                lo = mid;
            } else hi = mid-1;
        }
        c[i]=lo;
        left-=c[i];
        s-=c[i]*ll(i);
    }
    for(int i=1;i<n;++i) c[i]+=c[i-1];
    vi par(n+1);
    for(int i=1;i<n;++i) {
        int start = i==1?1:c[i-2]+1;
        for(int j=c[i-1]+1;j<=c[i];++j) {
            
            par[j] =start +(j-c[i-1]-1)/branch;
        }
    }
    par.erase(par.begin(),par.begin()+2);
    cout << par;
}
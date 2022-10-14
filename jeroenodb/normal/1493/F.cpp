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
const int store=1e3 + 1;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
int nn,mm;
bool vertical;
int tests=0;
bool test(int l, int r, int n) {
    tests++;
    // return 1;
    cout << "? ";
    if(vertical) {
        cout << vi{n,mm,l+1,1,r+1,1} << endl;
    } else {
        cout << vi{nn,n,1,l+1,1,r+1} << endl;
    }
    int t; cin >> t;
    return t==1;
}
// binary search the answer for the number c
int check(int p, int cnt, int n) {
    if(p==2) {
        int ans = 0;
        if(cnt <= 1+ ceil(log2(cnt))) {
            while(ans <cnt and test(0,n/2, n/2)) {
                n/=2;
                ans++;
            }
        } else {

            if(!test(0,n/2,n/2)) {
                return 0;
            }
            int l = 1, r=cnt;
            while(l<r) {
                int mid = (l+r+1)/2;
                // check 2**mid
                int blocks = 1<<mid;
                int len = n/blocks;
                if(!test(0,len*((blocks/2)-1),len*((blocks/2)-1))) {
                    r=mid-1;
                } else {
                    l=mid;
                }
            }
            ans = l;
        }
        return ans;
    } else {
        int l = 0, r = cnt;
        while(l<r) {
            int mid = (l + r+1) /2;
            int blocks = 1;
            for(int i=0;i<mid;++i) {
                blocks*=p;
            }
            // blocks is odd, two queries per binary search iteration suffice
            int len = n/blocks;
            if(!test(0, blocks/2 * len, blocks/2 * len) or !test(0, (1 + blocks/2) * len, blocks/2 * len)) {
                r = mid-1;
            } else {
                l= mid;
            }
        }
        return l;
    }
}
int getans(int n, bool vert = true) {
    vertical = vert;
    int ans = 1;
    int ori = n;
    while(n!=1) {
        int tmp = 0;
        int f = factor[n];
        while(f==factor[n]) {
            tmp++;
            n/=f;
        }
        ans*=1+check(f,tmp,ori);
    }
    return ans;
}
void solve(int n, int m) {
    nn =n, mm = m;

    int r = getans(nn);
    int c = getans(mm,false);
    cout << "! " << r*c << endl;
    
}

int main() {
    makesieve();
    // pair<double,pi> best = {-oo,{-1,-1}};
    // for(int i=100000;i<=1000000;++i) {
    //     for(int j=i;j<=i;++j) {
    //         tests=0;
    //         solve(i,j);
    //         // auto mx = floor(2*log2(i+j));
    //         // if(tests>=mx)
    //         //     cout << i << ' ' << j <<  ' ' << tests << "/" << mx << endl;
    //         // if(tests>mx) {
    //         //     cout << "Whoops!\n";
    //         // }
    //         best = max(best,{tests/(log2(i)+log(j)),{i,j}});
    //     }
    // }
    // debug(best);

    int r,c; cin >> r >> c;
    solve(r,c);
}
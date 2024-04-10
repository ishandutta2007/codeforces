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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vvi a(n);
    for(auto& i : a) {
        i.resize(m);
        for(auto& j :i) cin >> j;
    }
    auto check = [&](auto check, vi b, bool error=true) {
        for(int i=0;i<n;++i) {
            int cnt=0;
            for(int j=0;j<m;++j) if(a[i][j]!=b[j]) cnt++;
            if(cnt>2+error) return;
            if(cnt==3) {
                for(int j=0;j<m;++j) if(a[i][j]!=b[j]) {
                    vi c = b;
                    c[j] = a[i][j];
                    check(check,c,false);
                }
                return;
            }
        }
        cout << "Yes\n";
        cout << b << '\n';
        exit(0);
    };
    for(int j=1;j<n;++j) {
        vi errors;
        for(int i=0;i<m;++i) if(a[0][i]!=a[j][i]) errors.push_back(i);
        if(errors.size()>=3 and errors.size()<=4) {
            for(int i=0;i<1<<errors.size();++i) {
                vi b = a[0];
                for(int k=0;k<errors.size();++k) if((i>>k)&1) {
                    b[errors[k]]=a[j][errors[k]];
                }
                check(check,b);
            }
        } 
        if(errors.size()>2) {
            cout << "No\n";
            exit(0);
        }
    }
    cout << "Yes\n";
    cout << a[0] << '\n';
}
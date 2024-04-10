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
const int mxN = 505, oo = 1e9;
int mdp[mxN][mxN][21];
typedef complex<int> pt;
#define X real()
#define Y imag()

const pt dir[] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
bool inside(pt a) {
    return 0<=a.X and a.X < n and 0<=a.Y and a.Y < m;
}
int& dp(pt p, int k) {
    return mdp[p.X][p.Y][k];
}
void mins(int& a, int b) {
    a = min(a,b);
}
void relax(pt p, int k, vvi& re, vvi& de) {
    for(int i=0;i<4;++i) {
        auto d = dir[i];
        pt to = p+d;
        if(inside(to)) {
            int edge=-1234;
            switch(i) {
                case 0:
                    edge = re[p.X][p.Y];
                    break;
                case 1:
                    edge = de[p.X][p.Y];
                    break;
                case 2:
                    edge = re[to.X][to.Y];
                    break;
                case 3:
                    edge = de[to.X][to.Y];
                    break;
            }
            mins(dp(to,k+1), dp(p,k)+edge);
        }
    }
}
int main() {
    int k; cin >> n >> m >> k;

    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            for(int l=1;l<=k/2;++l) {
                mdp[i][j][l] = oo;
            }
        }
    }


    vvi de(n,vi(m-1));
    for(auto& v : de) {
        for(auto& p : v) cin >> p;
    }
    vvi re(n-1, vi(m));
    for(auto& v : re) {
        for(auto& p : v) cin >> p;
    }
    if(k%2!=0) {
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                cout << "-1 ";
            }
            cout << '\n';
        }
        exit(0);
    }
    k/=2;
    for(int l=0;l<k;++l) {
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {

                relax({i,j},l,re,de);
            }
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cout << 2*mdp[i][j][k] << ' ';
        } cout << '\n';
    }
}
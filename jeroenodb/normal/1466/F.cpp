
#pragma GCC optimize "Ofast"
#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 5e5+1, MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> next(m,-2);
    auto one = [&](int a) {
        if(next[a]==-2) {
            next[a] = -1;
        } else {
            while(next[a]>=0) {
                int b = next[a];
                next[a]=-1;
                a=b;
            }
            if(next[a]==-2) {
                next[a]=-1;
            } else {
                return false;
            }
        }
        return true;
    };
    
    auto two = [&](int a, int b) {
        if(next[a]==-2) {
            next[a]=b;
        } else {
            while(next[a]>=0) {
                if(next[a]==b) return false;
                int c = next[a];
                next[a] = max(b,c);
                a = b; b = c;      
                if(a>b) swap(a,b);
            }
            if(next[a]==-1) {
                return one(b);
            } else {
                next[a] = b;
            }
        }
        return true;
    };
    vector<int> s;
    for(int i=0;i<n;++i) {
        int k; cin >> k;
        if(k==1) {
            int a;  cin >> a;--a;
            if(one(a))  s.push_back(i+1);
        } else if(k==2) {
            int a,b; cin >> a >> b;
            --a,--b;
            if(a>b) swap(a,b);
            if(two(a,b)) s.push_back(i+1);
        }
    }
    ll ans = 1;
    for(int i=0;i<s.size();++i) {
        ans = (2*ans);
        while(ans>=MOD) ans-=MOD;
    }
    cout << ans << ' ' << s.size() << endl;
    for(int i: s) {
        cout << i << ' ';
    }
}
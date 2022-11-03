#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int sz = 0;
vector<int> pa;
vector<int> g[2];
vector<int> cnt;

void add(int x){
    int cur = 0;
    for(int w = (1 << 29); w > 0; w >>= 1){
        int digit = (!(x & w) ? 0 : 1);
        if(g[digit][cur] == -1){
            g[digit][cur] = sz;
            pa.push_back(cur);
            g[0].push_back(-1);
            g[1].push_back(-1);
            cnt.push_back(1);
            cur = sz;
            ++sz;
        }else{
            cur = g[digit][cur];
            ++cnt[cur];
        }
    }
}

int get(int x){
    int cur = 0;
    int res = 0;
    for(int w = (1 << 29); w > 0; w >>= 1){
        int digit = (!(x & w) ? 0 : 1);
        if(g[digit][cur] == -1 || cnt[g[digit][cur]] == 0){
            cur = g[1 - digit][cur];
            res += (1 - digit) * w;
        }else{
            cur = g[digit][cur];
            res += (digit) * w;
        }
    }
    while (cur >= 0) {
        --cnt[cur];
        cur = pa[cur];
    }
    return res ^ x;
}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n), p(n), o(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sz = 1;
    pa.push_back(-1);
    g[0].push_back(-1);
    g[1].push_back(-1);
    cnt.push_back(0);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        add(p[i]);
    }
    for(int i = 0; i < n; ++i){
        o[i] = get(a[i]);
    }
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << o[i];
    }
    cout << endl;



}
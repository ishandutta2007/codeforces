#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 100005;

int n, k, p[N], r;

int f(int x){
    if(p[x] == x) return x;
    return p[x] = f(p[x]);
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    iota(p, p + n + 1, 0);
    for(int x, y; k--; ){
        cin >> x >> y;
        if(f(x) == f(y)) r++;
        else p[f(y)] = f(x);
    }
    cout << r << '\n';
}
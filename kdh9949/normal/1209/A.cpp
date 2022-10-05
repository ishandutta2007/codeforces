#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 105;

int n, a[N], r;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        a[x] = 1;
    }
    for(int i = 1; i <= 100; i++){
        if(!a[i]) continue;
        r++;
        for(int j = i; j <= 100; j += i) a[j] = 0;
    }
    cout << r << '\n';
}
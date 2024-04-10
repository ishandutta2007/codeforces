#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, k, x;
llint a[MAXN];
vector <llint> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        llint d = a[i] - a[i - 1];
        llint br = (d + x - 1) / x - 1;
        if (d == 0) br = 0;
        v.push_back(br);
    }
    sort(v.rbegin(), v.rend());
    while (!v.empty() && k >= v.back()) {
        k -= v.back();
        v.pop_back();
    }
    cout << v.size() + 1;
    return 0;
}
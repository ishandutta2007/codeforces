#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

int main() {
    int i, j, n, k, a;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int nd = 0;
    for (i = 0; i < n; ++i) {
        cin >> a;
        nd = nod(nd, a);
    }
    vector <int> v;
    v.push_back(0);
    for (i = 1; i < k; ++i)
    if (nod(k, i) % nod(nd, k) == 0)
        v.push_back(i);
    cout << v.size() << "\n";
    for (i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
}
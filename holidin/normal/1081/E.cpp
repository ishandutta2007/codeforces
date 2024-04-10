#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

unordered_map <long long, bool> m;
long long a[N], c[N];
vector <long long> v;

int main() {
    int i, j, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long l = 1; l * l <= 1e12; ++l) {
        m[l * l] = true;
        v.push_back(l * l);
    }
    for (i = 1; i <= n / 2; ++i)
        cin >> c[i];
    j = 0;
    long long pr = 0;
    for (i = 1; i <= n / 2; ++i) {
        while (j < v.size() && (!m[v[j] + c[i]]))
            ++j;
        a[i] = v[j] - pr;
        pr = v[j] + c[i];
        while (j < v.size() && v[j] <= pr)
            ++j;
    }
    if (j == v.size()) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for (i = 1; i <= n / 2; ++i)
        cout << a[i] << ' ' << c[i] << ' ';
}
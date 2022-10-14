#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 5005;
const int OFS = 1e9 / 2;

int n, m, sol;
vector <int> v;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        v.push_back((i - 1) / 2);
        if (m - v.back() > 0) {
            a[i] = a[i - 1] + 1;
            m -= v.back();
        } else {
            for (int j = 0; j < v.size(); j++) {
                if (m == v[j]) {
                    a[i] = a[i - 1] + v.size() - j;
                    break;
                }
            }
            for (int j = i + 1; j <= n; j++) {
                a[j] = OFS + j * MAXN * 3;
            }
            for (int j = 1; j <= n; j++) cout << a[j] << " ";
            return 0;
        }
    }
    if (m > 0) {
        cout << -1;
        return 0;
    }
    return 0;
}
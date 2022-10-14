#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int n;
int a[MAXN];
pi p[MAXN];
vector <pi> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (a[i] > p[j].first && i < p[j].second) v.push_back({i + 1, p[j].second + 1});
        }
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}
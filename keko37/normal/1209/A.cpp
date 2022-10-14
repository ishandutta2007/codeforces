#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n;
int a[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i=0; i<n; i++) {
        bool naso = 0;
        for (auto x : v) {
            if (a[i] % x == 0) naso = 1;
        }
        if (!naso) v.push_back(a[i]);
    }
    cout << v.size();
    return 0;
}
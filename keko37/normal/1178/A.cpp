#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 105;

int n, sum, uzeo;
int a[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        if (i == 1 || a[i] * 2 <= a[1]) {
            uzeo += a[i];
            v.push_back(i);
        }
    }
    if (uzeo * 2 > sum) {
        cout << v.size() << endl;
        for (int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
    } else {
        cout << 0;
    }
    return 0;
}
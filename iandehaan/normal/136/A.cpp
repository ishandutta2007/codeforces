#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x-1] = i+1;
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
}
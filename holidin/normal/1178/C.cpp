#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;
const int mod = 998244353;
vector <int> ans;
int a[N];

int main() {
    int i, j, k, n, w, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> w >> h;
    j = 1;
    for (i = 1; i <= w + h; ++i)
        j = (j * 2) % mod;
    cout << j;
}
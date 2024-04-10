#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;
int cnt = 0;
bool flag = 0;
vector <int> e[N];

int main() {
    int i, j, k, n, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int start = 0;
    for (i = 1; i <= n; ++i)
    if (e[i].size() == 2)
        flag = 1;
    if (flag)
        cout << "NO";
    else
        cout << "YES\n";

}
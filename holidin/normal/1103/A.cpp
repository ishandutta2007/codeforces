#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 1;

int main() {
    string s;
    int i, j, q, tr, top = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    int top1 = 0, top2 = 0;
    for (i = 0; i < s.size(); ++i)
    if (s[i] == '0') {
        top1 = (top1 + 1) % 4;
        cout << 1 << ' ' << top1 + 1 << endl;
    } else {
        top2 = (top2 + 2) % 4;
        cout << 3 << ' ' << top2 + 1 << endl;
    }
}
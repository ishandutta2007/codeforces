#include <bits/stdc++.h>
 
using namespace std;
#define files1 freopen("input.txt", "r", stdin)
#define pb push_back
#define endl '\n'
#define f first
#define s second
#define mp make_pair
const int maxn = 3e5 + 128, inf = 2e9;
string a, b;
 
int p[maxn], is_del[maxn];
 
bool can(int c) {
    memset(is_del, 0, sizeof(is_del));
 
    for (int i = 0; i < c; i++)
        is_del[p[i] - 1] = 1;
 
    int j = 0;
    for (int i = 0; j < b.size() && i < a.size(); i++) {
        if (is_del[i]) continue;
        if (a[i] == b[j]) {
            j++;
        }
    }
    return j == b.size();
}
     
int main() {
    ios_base::sync_with_stdio(0);
    // files1;
    cin >> a >> b;
 
    int n = a.size();
 
    for (int i = 0; i < n; i++)
        cin >> p[i];
 
    int l = 0, r = n - 1;
    while (r - l > 1) {
        int c = (l + r) >> 1;
        if (can(c))
            l = c;
        else
            r = c;
    }
    if (can(r))
        cout << r;
    else
        cout << l;    
    return 0;
}
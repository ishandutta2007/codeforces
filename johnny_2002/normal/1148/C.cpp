#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 3e5 + 10;
int n;
int a[N], pos[N];
vector<ii> ans;
void mySwap(int x, int y) {
    if (x == y) return;
    
    assert(2 * abs(y - x) >= n);
    swap(a[x], a[y]);
    pos[a[x]] = x, pos[a[y]] = y;
    ans.push_back(ii(x, y));
}
int main() {
    cin >> n; 
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pos[a[i]] = i;

    if (pos[n] <= n / 2) {
        mySwap(pos[n], n);
    } else {
        mySwap(pos[n], 1);
        mySwap(1, n);
    }
        
    if (pos[1] < n / 2) {
        mySwap(n, 1);
        mySwap(pos[1], n);
        mySwap(n, 1);
    } else {
        mySwap(1, pos[1]);
    }
    
    for(int i = 2; i <= n / 2; i++) {
        mySwap(n, i);
        if (pos[i] <= n / 2) {
            mySwap(pos[i], n);
        } else {
            mySwap(1, n);
            mySwap(pos[i], 1);
            mySwap(1, n);
        }
        mySwap(n, i);
    }
    for(int i = n / 2 + 1; i < n; i++) {
        mySwap(1, i);
        if (pos[i] >= n / 2) {
            mySwap(pos[i], 1);
        } else {
            mySwap(1, n);
            mySwap(pos[i], n);
            mySwap(1, n);
        }
        mySwap(1, i);
    }
    for(int i = 1; i <= n; i++) assert(a[i] == i);
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i.X << " " << i.Y << '\n';
}
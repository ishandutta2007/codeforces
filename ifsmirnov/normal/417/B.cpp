#include <iostream>
#include <cstring>
#include <cstdlib>
#include<algorithm>
using namespace std;const int maxn = 100500;

int a[maxn];

int main() {
    int n;
    memset(a, -1, sizeof a);
    cin >> n;
    for (int i = 0; i < n;++i) {

        int x, t;
        cin >> x >> t;
        if (a[t] < x-1) {
            cout << "NO" << endl;
            return 0;
        }
        a[t] = max(a[t], x);
    }
    cout << "YES" << endl;
}
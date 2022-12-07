#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 11111;
int n;
int a[N];
bool used[N];
bool f[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    cin >> n;
    int x;
    cin >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> b;
    int cnum = -1;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0 && !used[i]) {
            bool have = 0;
            used[i] = true;
            if (i == x) { 
                cnum = 1;
                have = true;
            }
            
            int cur = i;
            int num = 1;
            while (true) {
                bool found = false;
                int nxt;
                for (int j = 1; j <= n; ++j)
                    if (a[j] == cur) {
                        nxt = j;
                        used[j] = true;
                        found = true;
                        if (j == x) {
                            have = true;
                            cnum = num + 1;
                        }
                        break;
                    }
                if (!found) {
                    break;
                }
                num++;
                cur = nxt;
            }
            if (!have) {
                b.push_back(num);
            }
        }

    f[0] = true;
    for (int j = 0; j < b.size(); ++j)
        for (int i = n; i >= 0; --i)
            if (f[i]) f[i + b[j]] = true;

    vector<int> ans;
    for (int i = 0; i <= n; ++i)
        if (f[i]) ans.push_back(i + cnum);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

const int N = 222;
int m, k;
int fav[N];
int mn[N], mx[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        fav[x] = true;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int d; cin >> d;
        int cool = 0;
        int unknown = 0;
        for (int j = 0; j < d; ++j) {
            int x;
            cin >> x;
            if (x == 0) {
                unknown++;
                continue;
            }
            if (fav[x]) ++cool;
        }

        int lastcool = k - cool;
        int lastuncool = (m - k) - (d - cool - unknown);
//        cout << "cool = " << cool << endl;
  //      cout << "lastcool = " << lastcool << endl;
    //    cout << "lastuncool = " << lastuncool << endl;
      //  cout << "unknown = " << unknown << endl;
        mx[i] = cool + min(unknown, lastcool);
        if (lastuncool >= unknown) {
            mn[i] = cool;
        } else {
            mn[i] = cool + unknown - lastuncool;
        }

//        cout << i << " " << mn[i] << " " << mx[i] << endl;
    }

    for (int i = 0; i < n; ++i) {
        bool willbefav = true, willbenotfav = false;
        for (int j = 0; j < n; ++j)
            if (i != j) {
                if (mn[i] < mx[j]) {
                    willbefav = false;
                }
                if (mx[i] < mn[j]) {
                    willbenotfav = true;
                }
            }

        if (willbefav) {
            cout << 0 << endl;
            continue;
        }
        if (willbenotfav) {
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }

    return 0;
}
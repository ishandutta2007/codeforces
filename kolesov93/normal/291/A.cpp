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
#include <map>

using namespace std;

map<int, int> q;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        q[x]++;
    }

    int ans = 0;
    bool cool = true;
    for (map<int, int>::iterator it = q.begin(); it != q.end(); ++it)
        if (it->first != 0) {
            if (it->second > 2) {
                cool = false;
                break;
            }
            if (it->second == 2) {
                ++ans;
            }
        }

    if (!cool) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
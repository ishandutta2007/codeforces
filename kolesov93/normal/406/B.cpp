#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;

const ld PI = acosl(-1.);
const int N = 1000111;
bool used[N];
ll sum = 0;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    while (n--) {
        int x; scanf("%d", &x);
        sum += x - 1;
        used[x] = 1;
    }

    int m = 1000000;
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        if (used[i] && !used[m - i + 1]) {
            used[m - i + 1] = 1;
            sum -= i - 1;
            ans.push_back(m - i + 1);
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        if (sum != 0 && !used[i] && !used[m - i + 1]) {
            ans.push_back(i);
            ans.push_back(m - i + 1);
            used[i] = used[m - i + 1] = true;
            sum -= m - 1;
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
    puts("");
    
    return 0;
}
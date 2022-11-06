#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int ask(int x) {
    printf("%d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    if (x != 0) return x;
    exit(0);
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int lie[100];
    for (int i = 0; i < n; ++i) {
        lie[i] = (ask(1) == -1);
    }
    
    int i = 0;
    int s = 1, e = m;
    while (s <= e) {
        int mid = (s + e) / 2;
        int x = ask(mid);
        if (lie[i]) x = -x;
        if (x < 0) e = mid - 1;
        else s = mid + 1;
        i = (i + 1) % n;
    }
    
	return 0;
}
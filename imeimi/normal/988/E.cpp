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

int check(char str[20], const char ch[3]) {
    int n = strlen(str), i, ret = 0;
    for (i = n; i--; ) {
        if (str[i] == ch[1]) break;
    }
    if (i < 0) return 1000;
    ret += n - i - 1;
    for (; i < n; ++i) {
        str[i] = str[i + 1];
    }
    
    for (i = n - 1; i--; ) {
        if (str[i] == ch[0]) break;
    }
    if (i < 0) return 1000;
    ret += n - i - 2;
    for (; i < n - 1; ++i) {
        str[i] = str[i + 1];
    }
    
    for (i = 0; i < n - 2; ++i) {
        if (str[i] != '0') break;
    }
    if (i == n - 2) return 1000;
    ret += i;
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	char str[20];
	char tmp[20];
	int val[100] = { 0 };
	llong n;
	cin >> n;
	if (n < 100) {
        if (n < 10) printf("-1\n");
        else {
            val[25] = 1;
            val[50] = 1;
            val[75] = 1;
            val[52] = 2;
            val[57] = 2;
            printf("%d\n", val[n] - 1);
        }
        return 0;
	}
	sprintf(str, "%lld", n);
	int ans = 1000;
	strcpy(tmp, str);
	ans = min(ans, check(tmp, "00"));
	strcpy(tmp, str);
	ans = min(ans, check(tmp, "25"));
	strcpy(tmp, str);
	ans = min(ans, check(tmp, "50"));
	strcpy(tmp, str);
	ans = min(ans, check(tmp, "75"));
	printf("%d\n", ans < 1000 ? ans : -1);
	return 0;
}
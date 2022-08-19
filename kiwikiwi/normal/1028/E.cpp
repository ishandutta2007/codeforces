#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cassert>

using namespace std;
const int N = 200000;
int x[N], n;
long long ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] < x[(i + 1) % n]) {
            pos = (i + 1) % n;
        }
    }
    if (pos == -1) {
    	if (x[1] == 0) {
    		puts("YES");
    		for (int i = 0; i < n; i++) {
    			printf("1 ");
    		}
    		puts("");
    	} else {
        	puts("NO");
        }
        return 0;
    }
    puts("YES");
    ans[pos] = x[pos];
    for (int i = 1; i < n; i++) {
        long long P = ans[pos];
        pos = (pos + n - 1) % n;
        ans[pos] = P + x[pos];
        if (i == 1) {
            ans[pos] = ans[pos] + 1ll * P * N;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    puts("");
    return 0;
}
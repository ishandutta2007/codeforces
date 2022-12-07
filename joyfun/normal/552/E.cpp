#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

char str[5005];

int len;

int v[20], vn;

ll num[5005];

ll gao(int l, int r) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < len; i += 2) num[i] = str[i] - '0';
    for (int i = l + 1; i <= r - 3; i += 2) {
        if (str[i + 1] == '*') {
            num[i + 2] *= num[i];
            num[i] = 0;
        }
    }
    ll sum = 0;
    for (int i = l + 1; i <= r - 1; i += 2)
        sum += num[i];
    num[l + 1] = sum;
    for (int i = l + 3; i <= r - 1; i += 2) num[i] = 1;
    for (int i = 0; i < len - 2; i += 2) {
        if (i >= l + 1 && i <= r - 3) {
            num[i + 2] *= num[i];
            num[i] = 0;
        } else {
            if (str[i + 1] == '*') {
                num[i + 2] *= num[i];
                num[i] = 0;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < len; i += 2) ans += num[i];
    return ans;
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    v[vn++] = -1;
    for (int i = 1; i < len; i += 2)
        if (str[i] == '*') v[vn++] = i;
    v[vn++] = len;
    ll ans = 0;
    for (int i = 0; i < vn; i++) {
        for (int j = i + 1; j < vn; j++) {
            ans = max(ans, gao(v[i], v[j]));
        }
    }
    cout << ans << endl;
    return 0;
}
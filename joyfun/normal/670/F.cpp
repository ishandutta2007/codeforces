#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1000005;
char str[N];
int cnt[10], tmp[10];
int len, n;

bool judge(int x) {
    for (int i = 0; i < 10; i++) tmp[i] = cnt[i];
    if (!x) tmp[0]--;
    int ca = 0, xx = x;
    while (x) {
        ca++;
        tmp[x % 10]--;
        if (tmp[x % 10] < 0) return false;
        x /= 10;
    }
    if (n - ca !=  xx) return false;
    if (str[0] == '0') {
        int f = 0;
        for (int i = 1; i < 10; i++) {
            if (tmp[i]) {
                f = 1;
                break;
            }
        }
        if (f == 0)
            return false;
    }
    return true;
}

bool big(int a, int b) {
    char aa[10], bb[10];
    int an = 0, bn = 0;
    if (!a) aa[an++] = '0';
    while (a) {
        aa[an++] = a % 10 + '0';
        a /= 10;
    }
    if (!b) bb[bn++] = '0';
    while (b) {
        bb[bn++] = b % 10 + '0';
        b /= 10;
    }
    sort(aa, aa + an); reverse(aa, aa + an);
    sort(bb, bb + bn); reverse(bb, bb + bn);
    aa[an] = 0;
    bb[bn] = 0;
    return strcmp(aa, bb) > 0;
}

string ans;
void cao() {
    ans = "z";
    string tmp = "";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++)
            tmp += i + '0';
    }
    if (str[0] != '0') ans = min(ans, str + tmp);
    tmp = "";
    int f = 0;
    for (int i = 1; i < 10; i++) {
        if (cnt[i]) {
            f = 1;
            tmp +=  i + '0';
            cnt[i]--;
            break;
        }
    }
    if (!f) return;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++)
            tmp += i + '0';
    }
    for (int i = 1; i < tmp.length(); i++) {
        if (i == 1 || tmp[i] != tmp[i - 1]) {
            string sb = tmp;
            sb.insert(i, str);
            ans = min(ans, sb);
        }
    }
    ans = min(ans, tmp + str);
}

bool nima() {
    if (cnt[0] != 1 || cnt[1] != 1) return false;
    if (strcmp(str, "0") != 0) return false;
    return true;
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    n = len;
    for (int i = 0; i < len; i++) {
        cnt[str[i] - '0']++;
    }
    scanf("%s", str);
    len = strlen(str);
    if(nima()) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < len; i++)
        cnt[str[i] - '0']--;
    int x = -1;
    for (int i = 0; i <= 1000000; i++) {
        if (judge(i)) {
            if (x == -1) x = i;
            if (big(i, x)) x = i;
        }
    }
    //printf("%d\n", x);
    while (x) {
        cnt[x % 10]--;
        x /= 10;
    }
    cao();
    cout << ans << endl;
    return 0;
}
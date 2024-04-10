#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 1000005;
int n, k;
char str[N];

int jp[N], jump[N], ans[N];

void kmp() {
	int j = 0;
	for (int i = 2; i <= n; i++) {
		while (j && str[j + 1] != str[i]) j = jp[j];
		if (str[j + 1] == str[i]) j++;
		jp[i] = j;
	}
}

void exkmp() {
    jump[1] = n;
    int k = 1;
    while (k + 1 <= n && str[k] == str[k + 1]) k++;
    jump[2] = k - 1;
    k = 2;
    for (int i = 3; i <= n; i++) {
        if (jump[i - k + 1] + i - 1 < jump[k] + k - 1) jump[i] = jump[i - k + 1];
        else {
            int j = max(0, jump[k] + k - 1 - i);
            while (i + j <= n && str[j + 1] == str[j + i]) j++;
            jump[i] = j;
            k = i;
        }
    }
}

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	kmp(); exkmp();
	for (int i = 1; i <= n; i++) {
		int len = i - jp[i];
		if (i % len) continue;
		len = i / len;
		if (len % k || i % k) continue;
		ans[i]++;
		ans[i + min(i / k, jump[i + 1]) + 1]--;
	}
	for (int i = 1; i <= n; i++) ans[i] += ans[i - 1], printf("%d", ans[i] >= 1); printf("\n");
	return 0;
}
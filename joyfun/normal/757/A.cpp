#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;
char a[10] = "Blbrsau";
char s[N];
int cnt[10];

int main() {
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 9; j++)
			if (s[i] == a[j]) cnt[j]++;
	}
	int Min = INF;
	for (int i = 0; i < 5; i++) Min = min(Min, cnt[i]);
	for (int i = 5; i < 7; i++) Min = min(Min, cnt[i] / 2);
	printf("%d\n", Min);
	return 0;
}
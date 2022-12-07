#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MP(a,b) make_pair(a,b)
const int N = 100005;
typedef pair<int, int> pii;

char a[N][55], b[N][55];

int n;
pii p[N];
char sb[55];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", a[i], b[i]);
		if (strcmp(a[i], b[i]) > 0) {
			strcpy(sb, a[i]);
			strcpy(a[i], b[i]);
			strcpy(b[i], sb);
		}
	}
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		p[i] = MP(i, tmp - 1);
	}
	sort(p, p + n);
	char pre[55];
	int flag = 0;
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; i++) {
		int id = p[i].second;
		if (strcmp(a[id], pre) > 0) {
			strcpy(pre, a[id]);
		} else if (strcmp(b[id], pre) > 0) {
			strcpy(pre, b[id]);
		} else {
			flag = 1;
			break;
		}
	}
	if (flag) printf("NO\n");
	else printf("YES\n");
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[3010];
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < 2*n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w, w + 2 * n);
	long long s1 = 0, s2 = 0;
	for (i = 0; i < n; i++) s1 += w[i], s2 += w[n+i];
	if(s1 != s2){
		for (i = 0; i < 2 * n; i++)printf("%d ", w[i]);
		return 0;
	}
	else {
		puts("-1");
	}
}
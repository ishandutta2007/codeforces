#include <cstring>
#include <cstdio>
#include <vector>

char s[200010];
std :: vector<int> ans[200010];

int main() {
	gets(s);
	int n = strlen(s), p = 0;
	int k1 = -1, k2;
	for(int i=0; i<n; i++) {
		if(s[i] == '1') {
			if(!p) return puts("-1"), 0;
			ans[-- p].push_back(i + 1);
		} else {
			ans[p ++].push_back(i + 1);
			if(p > k1) k1 = p;
		}
	}
	if(k1 != p) return puts("-1"), 0;
	printf("%d\n", k1);
	for(int i=0; i<k1; i++) {
		printf("%d ", k2 = ans[i].size());
		for(int j=0; j<k2; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 22;

char s[N];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) {
		s[i] -= '0';
		if(s[i] > 9 - s[i]) {
			if(i == 1 && s[i] == 9) continue ;
			s[i] = 9 - s[i];
		}
	}
	for(int i = 1; i <= n; i ++)
		printf("%d", s[i]);
	return 0;
}
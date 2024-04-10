#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1010;

char s[N];
int n;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int a = 0, b = 0;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '0') {
			if(a == 2) a = 0;
			if(a == 0) puts("1 1");
			else if(a == 1) puts("3 1");
			a ++;
		} else {
			if(b == 4) b = 0;
			if(b == 0) puts("1 2");
			else if(b == 1) puts("2 2");
			else if(b == 2) puts("3 2");
			else if(b == 3) puts("4 2");
			b ++;
		}
	}
	return 0;
}
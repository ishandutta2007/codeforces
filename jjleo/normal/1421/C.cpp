#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
char s[maxn];

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	printf("3\nL %d\n", 2);
	printf("R %d\n", 2);
	printf("R %d\n", 2 * n - 1);
}
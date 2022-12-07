#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
char str[N];

int main() {
	scanf("%d", &n);
	scanf("%s", str);
	int a = 0;
	for (int i = 0; i < n; i++) a += (str[i] == 'A');
	int b = n - a;
	if (a == b) printf("Friendship\n");
	else if (a < b) printf("Danik\n");
	else printf("Anton\n");
	return 0;
}
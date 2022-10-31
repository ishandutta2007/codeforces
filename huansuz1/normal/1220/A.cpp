#include <bits/stdc++.h>
using namespace std;
 
const int N = int(2e5) + 228;

char s[N];

int n;

map <char, int> ma;
 
int main() {
	scanf("%d\n%s", &n, s);
	for(int i = 0; i < n; i++){
		ma[s[i]]++;
	}
	int x = ma['n'];
	int y = ma['z'];
	for(int i = 0; i < x; i++){
		printf("1 ");
	}
	for(int i = 0; i < y; i++){
		printf("0 ");
	}

	return 0;
}
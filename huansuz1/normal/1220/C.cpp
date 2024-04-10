#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
const int N = int(5e5) + 228;

int ok[N], n;
char s[N];
 
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int mn = 30;
	for(int i = 1; i <= n; i++){
		int x = s[i] - 'a';
		if(x > mn){
			puts("Ann");
		}
		else {
			puts("Mike");
			mn = x;
		}
	}
 
 
	return 0;
}
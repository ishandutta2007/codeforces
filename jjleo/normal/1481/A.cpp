#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x, y;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &x, &y, s + 1);
		n = strlen(s + 1);
		int X = 0, Y = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == 'U' && y > 0) Y++;
			if(s[i] == 'D' && y < 0) Y--;
			if(s[i] == 'R' && x > 0) X++;
			if(s[i] == 'L' && x < 0) X--;
		}
		puts(abs(x) <= abs(X) && abs(y) <= abs(Y) ? "YES" : "NO");
	}	
}
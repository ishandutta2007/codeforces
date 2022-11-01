#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[100][100];

inline void change(int i, int j){
	s[i][j] = s[i][j] == '9' ? '1' : (s[i][j] + 1);
}

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1;i <= 9;i++) scanf("%s", s[i] + 1);
		change(1, 1), change(2, 4), change(3, 7);
		change(4, 2), change(5, 5), change(6, 8);
		change(7, 3), change(8, 6), change(9, 9);
		for(int i = 1;i <= 9;i++) printf("%s\n", s[i] + 1);
	}
}
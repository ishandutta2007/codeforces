#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char s[N];
int gc, sc;

int main(){
	scanf("%s", s);
	for(int i = 0; s[i]; i++){
		if(s[i] == '0'){
			printf("1 %d\n", gc % 4 + 1);
			gc++;
		}
		else{
			printf("3 %d\n", sc % 2 * 2 + 1);
			sc++;
		}
	}
}
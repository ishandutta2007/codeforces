#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		bool tag = false;
		for(int i = 0;i <= 4 && !tag;i++){
			string S = "";
			for(int j = 1;j <= i;j++) S += s[j];
			for(int j = 4 - i;j;j--) S += s[n + 1 - j];
			if(S == "2020") tag = true;
		}
		puts(tag ? "YES" : "NO");
	}
}
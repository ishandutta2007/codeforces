#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1), n = strlen(s + 1);
		bool tag = false;
		int ans = 0;
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '1'){
				if(!tag) tag = true;
				else ans += sum;
				sum = 0;
			}
			if(s[i] == '0') sum++;
		}
		printf("%d\n", ans);
	}
}
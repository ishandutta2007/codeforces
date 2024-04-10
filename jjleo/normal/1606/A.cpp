#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];
int n;

bool check(){
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1;i < n;i++){
		cnt1 += s[i] == 'a' && s[i + 1] == 'b';
		cnt2 += s[i] == 'b' && s[i + 1] == 'a';
	}
	return cnt1 == cnt2;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		if(check()){
			printf("%s\n", s + 1);
			continue;
		}
		for(int i = 1;i <= n;i++){
			int a = s[i];
			s[i] = 'a';
			if(check()){
				printf("%s\n", s + 1);
				break;
			}
			s[i] = 'b';
			if(check()){
				printf("%s\n", s + 1);
				break;
			}
			s[i] = a;
		}
	}
}
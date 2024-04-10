#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		bool tag1 = false, tag2 = false;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0'){
				if(!tag1) tag1 = true;
				else tag2 = true;
			}else if((s[i] - '0') % 2 == 0) tag2 = true;
			cnt += s[i] - '0'; 
		}
		puts(cnt % 3 == 0 && tag1 && tag2 ? "red" : "cyan");
	}
}
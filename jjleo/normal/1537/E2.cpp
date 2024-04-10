#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n, k;
char s[maxn];

int main(){
	scanf("%d%d%s", &n, &k, s);
	int x = -1;
	for(int i = 1;i < n;i++){
		if(s[i] > s[0]){
			for(int j = 0;j < k;j++) printf("%c", s[j % i]);
			return 0;
		}
		if(s[i] == s[0]){
			x = i;
			break;
		}
	}
	if(x == -1){
		for(int j = 0;j < k;j++) printf("%c", s[j % n]);
		return 0;
	}
	while(1){
		bool tag = false;
		for(int i = 0;i + x < n;i++){
			if(s[i + x] == s[i]) continue;
			if(s[i + x] < s[i]){
				tag = true;
				x = i + x + 1;
				break;
			}
			if(s[i + x] > s[i]){
				for(int j = 0;j < k;j++) printf("%c", s[j % x]);
				return 0;
			}
		}
		if(!tag){
			for(int j = 0;j < k;j++) printf("%c", s[j % x]);
			return 0;
		}
	}
}
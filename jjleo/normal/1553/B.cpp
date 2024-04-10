#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int T, n, m;
char s[maxn], t[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		bool flag = false;
		for(int i = 1;i <= m && !flag;i += 2){
			bool tag = false;
			for(int j = 1;j < i - j + 1;j++){
				if(t[j] != t[i - j + 1]){
					tag = true;
					break;
				}
			}
			if(tag) continue;
			for(int j = m - i + 1;j <= n && !flag;j++){
				bool tag = false;
				for(int k = 0;k < i / 2 + 1;k++){
					if(s[j + k] != t[k + 1]){
						tag = true;
						break;
					}
				}
				if(tag) continue;
				tag = false;
				for(int k = 0;k < m - i;k++){
					if(s[j - k - 1] != t[i + k + 1]){
						tag = true;
						break;
					}
				}
				if(tag) continue;
				flag = true;
			}
		}
		reverse(t + 1, t + 1 + m);
		for(int i = 1;i <= m && !flag;i += 2){
			bool tag = false;
			for(int j = 1;j < i - j + 1;j++){
				if(t[j] != t[i - j + 1]){
					tag = true;
					break;
				}
			}
			if(tag) continue;
			for(int j = m - i + 1;j <= n && !flag;j++){
				bool tag = false;
				for(int k = 0;k < i / 2 + 1;k++){
					if(s[j + k] != t[k + 1]){
						tag = true;
						break;
					}
				}
				if(tag) continue;
				tag = false;
				for(int k = 0;k < m - i;k++){
					if(s[j - k - 1] != t[i + k + 1]){
						tag = true;
						break;
					}
				}
				if(tag) continue;
				flag = true;
			}
		}
		/*
		for(int i = m;i > 0 && !flag;i -= 2){
			bool tag = false;
			for(int j = 0;i + j < m - j;j++){
				if(t[i + j] != t[m - j]){
					tag = true;
					break;
				}
			}
			if(tag) continue;
			for(int j = i;j <= n && !flag;j++){
				bool tag = false;
				for(int k = 0;k < (m - i + 1) / 2 + 1;k++){
					if(s[j + k] != t[i + k + 1]){
						tag = true;
						break;
					}
				}
				if(tag) continue;
				tag = false;
				for(int k = 0;k < m - i;k++){
					if(s[j - k - 1] != t[i + k + 1]){
						tag = true;
						break;
					}
				}
				if(tag) continue;
				flag = true;
			}
		}*/
		puts(flag ? "YES" : "NO");
	}
}
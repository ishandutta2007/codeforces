#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 500005;

char s[MAXN], t[MAXN];
int fail[MAXN];

int main(){
	scanf("%s %s",s, t);
	if(strlen(s) < strlen(t)){
		puts(s);
		return 0;
	}
	int p = 0;
	for(int i=1; t[i]; i++){
		while(p && t[i] != t[p]) p = fail[p];
		if(t[i] == t[p]) p++;
		fail[i + 1] = p;
	}
	int n = strlen(s);
	int m = strlen(t);
	int c0 = count(s, s + n, '0');
	int c1 = count(s, s + n, '1');
	p = 0;
	for(int i=0; i<n; i++){
		if(p < m){
			if(t[p] == '0' && c0){
				s[i] = '0';
				c0--;
				p++;
			}
			else if(t[p] == '1' && c1){
				s[i] = '1';
				c1--;
				p++;
			}
			else if(c0){
				s[i] = '0';
				c0--;
			}
			else if(c1){
				s[i] = '1';
				c1--;
			}
			if(p == m){
				p = fail[p];
			}
		}
	}
	puts(s);
}
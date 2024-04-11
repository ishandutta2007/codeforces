#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int nxt[10005][26], n;
char s[10005], t[1000005];

int main(){
	scanf("%s %s", s, t);
	n = strlen(s);
	for(int i=0; i<26; i++) nxt[n][i] = -1;
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<26; j++){
			nxt[i][j] = nxt[i+1][j];
		}
		nxt[i][s[i] - 'a'] = i;
	}
	int pos = 0;
	int cnt = 1;
	for(int i=0; t[i]; i++){
		if(pos >= n){
			pos -= n;
			cnt++;
		}
		t[i] -= 'a';
		if(~nxt[pos][t[i]]){
			pos = nxt[pos][t[i]] + 1;
		}
		else{
			pos = 0;
			cnt++;
			if(~nxt[pos][t[i]]){
				pos = nxt[pos][t[i]] + 1;
			}
			else{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d\n", cnt);
}
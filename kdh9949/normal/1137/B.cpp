#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m, zer, one, fa[N];
char t[N], r[N];

int main(){
	scanf("%s", t);
	n = strlen(t);
	for(int i = 0; i < n; i++) (t[i] == '1' ? one : zer)++;
	scanf("%s", t);
	m = strlen(t);
	for(int i = 1, j = 0; i < m; i++){
		while(j > 0 && t[i] != t[j]) j = fa[j];
		if(t[i] == t[j]) j++;
		fa[i + 1] = j;
	}
	for(int i = 0, j = 0; i < n; i++){
		if(!zer || !one){
			if(zer){ r[i] = '0'; zer--; }
			else{ r[i] = '1'; one--; }
		}
		else{
			r[i] = t[j++];
			(r[i] == '1' ? one : zer)--;
			if(j == m) j = fa[j];
		}
	}
	puts(r);
}
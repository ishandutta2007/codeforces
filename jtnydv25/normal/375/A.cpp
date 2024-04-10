#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 1000006;
char s[N];

int perm[4] = {1, 6, 8, 9};
int cnt[10];
int main(){
	scanf("%s", s);
	int n = strlen(s);
	cnt[1] = cnt[6] = cnt[8] = cnt[9] = -1;
	for(int i = 0; i < n; i++) cnt[s[i] - '0']++;
	int md= 0;
	for(int i = 1; i <= 9; i++)
		for(int j = 0; j < cnt[i]; j++){
			printf("%d", i);
			md = (md * 10 + i) % 7;
		}
	int req;
	for(int i = 0; i < 7; i++) if((md * 10000 + i) % 7 == 0) req = i;
	do{
		int x = 0;
		for(int j = 0; j < 4; j++) x = (x * 3 + perm[j]) % 7;
		if(x == req){
			for(int i = 0; i < 4; i++) printf("%d", perm[i]);
			for(int i = 0; i < cnt[0]; i++) printf("0");
				break;
		}
	}
	while(next_permutation(perm, perm + 4));
}
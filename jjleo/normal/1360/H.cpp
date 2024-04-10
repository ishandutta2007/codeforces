#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n, m;
char s[200][200];
ll k;
bool tag[200];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		k = ((1ll << m) - n - 1) / 2 + 1;
		memset(tag, 0, sizeof(tag));
		for(int i = 1;i <= m;i++){
			ll x = 1ll << (m - i);
			for(int j = 1;j <= n;j++){
				if(s[j][i] == '0' && !tag[j]) x--;
			} 
			if(k <= x){
				printf("0");
				for(int j = 1;j <= n;j++){
					if(s[j][i] != '0') tag[j] = true;
				}
			}else{
				printf("1"), k -= x;
				for(int j = 1;j <= n;j++){
					if(s[j][i] != '1') tag[j] = true;
				}
			}
		}
		puts("");
	}
}
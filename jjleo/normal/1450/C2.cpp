#include <bits/stdc++.h>
#define maxn 305

using namespace std;

int t;
int n;
char s[maxn][maxn];
int a[3], b[3];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 0;i < 3;i++) a[i] = b[i] = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(s[i][j] == 'X') a[(i + j) % 3]++;
				else if(s[i][j] == 'O') b[(i + j) % 3]++;
			}
		}
		int x = 0;
		for(int i = 1;i <= 2;i++) if(a[i] + b[(i + 1) % 3] < a[x] + b[(x + 1) % 3]) x = i;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(s[i][j] == 'X' && (i + j) % 3 == x) s[i][j] = 'O';
				else if(s[i][j] == 'O' && (i + j) % 3 == (x + 1) % 3) s[i][j] = 'X';
			}
		}
		for(int i = 1;i <= n;i++) printf("%s\n", s[i] + 1);
	}
}
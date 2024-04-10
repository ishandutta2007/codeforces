#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

const int p = 998244353;

int n, k;
char s[maxn];
int C[maxn][maxn];

int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	if(!k) return printf("1"), 0;
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	int ans = 1;
	for(int i = 1;i <= n;i++){
		int sum = 0, pos = n;
		for(int j = i;j <= n;j++){
			sum += s[j] == '1';
			if(sum == k + 1){
				sum--;
				pos = j - 1;
				break;
			}
		}
		int val = sum;
		for(int j = i - 1;j && sum < k;j--) sum += s[j] == '1';
		if(sum < k) continue;
		//printf("%d %d--\n", i, pos); 
		if(s[i] == '1') ans = (ans + C[pos - i][val]) % p;
		else if(val >= 0) ans = (ans + C[pos - i][val - 1]) % p;
	}
	printf("%d", ans);
}
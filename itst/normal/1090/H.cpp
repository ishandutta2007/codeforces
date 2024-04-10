#include<bits/stdc++.h>
using namespace std;

int sum[200003][19] , N , Q;
char s[200003];

int main(){
	scanf("%d %s %d" , &N , s + 1 , &Q); s[0] = '0';
	for(int i = 1 ; i <= N + 1 ; ++i){
		int val = s[i] ^ s[i - 1];
		for(int j = 0 ; 1 << j <= N ; ++j)
			sum[i][j] = sum[i >= (1 << j) ? i - (1 << j) : 0][j] + val;
	}
	for(int i = 1 ; i <= Q ; ++i){
		int l , r , ans = 0; scanf("%d %d" , &l , &r); ++l; ++r;
		if(l == r){puts("0"); continue;}
		for(int j = 1 ; (1 << j) <= r - l ; ++j){
			int all = (r - l + 1) >> j , val = (sum[r + 1][j - 1] - sum[l][j - 1]) - (sum[r + 1][j] - sum[l][j]);
			ans += min(val , all - val);
		}
		printf("%d\n" , (ans + 1) / 2);
	}
	return 0;
}
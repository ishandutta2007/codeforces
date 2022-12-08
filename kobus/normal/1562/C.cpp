#include <bits/stdc++.h>
 
#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
 
using namespace std;
 
char s[N+1];
 
void solve(){
	int n;
	scanf("%d", &n);
 
	int zero = -1;
	for(int i = 0; i < n; i++){
		scanf(" %c", &s[i]);
		if(s[i] == '0') zero = i+1;
	}
 
	if(zero == -1){
		printf("%d %d %d %d\n", 1, n/2, n/2 + 1, n/2 + n/2);
	}
	else{
		if(zero >= n/2+1){
			printf("%d %d %d %d\n", 1, zero, 1, zero-1);
		}
		else{
			printf("%d %d %d %d\n", zero, n, zero+1, n);
		}
	}
}
 
int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;
 
}
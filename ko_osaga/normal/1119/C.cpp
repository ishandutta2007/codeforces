#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 505;
const int mod = 1e9 + 7;
using lint = long long;

int n, m, a[MAXN][MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				int x; scanf("%d",&x);
				a[j][k] ^= x;
			}
		}
	}
	for(int i=n-1; i; i--){
		for(int j=m-1; j; j--){
			if(a[i][j]){
				a[i][j] ^= 1;
				a[0][j] ^= 1;
				a[i][0] ^= 1;
				a[0][0] ^= 1;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
}
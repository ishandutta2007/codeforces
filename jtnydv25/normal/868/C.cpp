#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back

const int N = 1e5 + 10;
int A[4][N];

int cnt[1 << 4];
int x[4];

bool valid(int x, int y, int k){
	for(int i = 0; i < k; i++){
		if((x & (1 << i)) && (y & (1 << i)))
			return 0;
	}
	return 1;
}
int main(){
	int n, k;
	sd(n); sd(k);
	for(int i = 1; i <= n; i++){
		int v = 0;
		for(int j = 0; j < k; j++){
			sd(x[j]);
			v = (v * 2 + x[j]);
		}
		cnt[v]++;
	}	

	if(cnt[0] >= 1){
		printf("YES\n");
		return 0;
	}
	for(int i = 0; i < (1 << k); i++){
		for(int j = 0; j < (1 << k); j++){
			if((i != j) && cnt[i] && cnt[j] && valid(i, j, k)){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
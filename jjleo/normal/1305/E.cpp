#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int a[maxn];
int sum;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		sum += (i - 1) / 2;
		if(sum >= m){
			a[i] = i + 2 * (sum - m);
			a[n + 1] = 1e9;for(int j = n;j > i;j--) a[j] = a[j + 1] - a[i] - 1;
			for(int j = 1;j <= n;j++) printf("%d ", a[j]);
			return 0;
		}
		a[i] = i;
	}//
	printf("-1");
}
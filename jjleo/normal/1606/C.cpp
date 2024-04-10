#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

#define int long long

int t, n, k;
int a[maxn];
int x;

signed main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &k), k++;
		for(int i = 0;i <= 9;i++) a[i] = 0;
		while(n--) scanf("%lld", &x), a[x] = 1;
		int sum = 0, val = 1;
		int last = -1;
		for(int i = 0;;i++){
			if(k < sum + val){
				printf("%lld", k - sum);
				for(int j = last - 1;j >= 0;j--) printf("9");
				puts("");
				break;
			}
			if(a[i]) last = i, sum += val - 1, val = 1;
			val *= 10;
		}
	}
}
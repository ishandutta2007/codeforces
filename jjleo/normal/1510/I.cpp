#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int a[maxn];
char s[maxn];
int x;

int main(){
	srand(time(0));
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%s", s + 1);
		int mn = *min_element(a + 1, a + 1 + n);
		long double sum0 = 0, sum1 = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0') sum0 += pow(0.75, a[i] - mn);
			else sum1 += pow(0.75, a[i] - mn);
		}
		printf("%d\n", 1.0 * rand() / RAND_MAX < sum1 / (sum0 + sum1)), fflush(stdout);
		scanf("%d", &x);
		for(int i = 1;i <= n;i++) a[i] += x ^ (s[i] - '0');
	}
}
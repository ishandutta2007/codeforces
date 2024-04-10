#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, m;
int l[maxn], p[maxn];
ll sum;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d", &l[i]);
		if(l[i] > n - i + 1) return printf("-1"), 0;
		sum += l[i];
	}
	if(sum < n) return printf("-1"), 0;
	int j = n;
	p[m + 1] = n + 1;
	for(int i = m;i;i--){
		while(n + 1 - j < l[i]) j--;
		while(j > i && j + l[i] - 1 >= p[i + 1]) j--;
		//printf("%d %d--\n", i, j);
		p[i] = j;
		j--;
	}
	if(p[1] ^ 1) return printf("-1"), 0;
	for(int i = 1;i <= m;i++) printf("%d ", p[i]);
	
}
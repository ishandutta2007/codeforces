#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
bool tag[maxn], on[maxn];
int x;

inline int cal(int x){
	return n - x - (n + x - 1) / x + 1;
}

int main(){
	scanf("%d", &n);
	if(n <= 3) return puts("0"), 0;
	int k = 1;
	for(int i = 2;i <= n;i++){
		if(cal(i) > cal(k)) k = i;
	}
	for(int i = 1;i <= n;i += k) tag[i] = true;
	int cnt = 0;
	while(1){
		if(cnt == cal(k)) return puts("0"), 0;
		printf("%d", k);
		int sum = k;
		for(int i = 1;i <= n && sum;i++){
			if(!tag[i] && !on[i]){
				on[i] = true;
				printf(" %d", i);
				sum--;
				cnt++;
			}
		}
		puts(""), fflush(stdout);
		scanf("%d", &x);
		for(int i = 1;i <= k;i++){
			if(on[x]) cnt--;
			on[x] = false;
			x++;
			if(x > n) x = 1;
		}
	}
}
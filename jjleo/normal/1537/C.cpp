#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int mn = a[2] - a[1], id = 2;
		for(int i = 3;i <= n;i++){
			if(a[i] - a[i - 1] < mn) mn = a[i] - a[i - 1], id = i;
		}
		printf("%d ", a[id - 1]);
		for(int i = id + 1;i <= n;i++) printf("%d ", a[i]);
		for(int i = 1;i < id - 1;i++) printf("%d ", a[i]);
		printf("%d\n", a[id]);
	}
}
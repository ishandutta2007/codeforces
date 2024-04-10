#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		long long sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			sum += a[i];
			if(sum < i - 1){
				tag = true;
				break;
			}
			sum -= i - 1;
		}
		puts(tag ? "NO" : "YES");
	}
}
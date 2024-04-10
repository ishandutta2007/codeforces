#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), sum += b[i];
		bool tag = true;
		for(int i = 2;i <= n;i++){
			if(a[i] < a[i - 1]){
				tag = false;
				break;
			}
		}
		puts((tag || (sum && sum < n)) ? "Yes" : "No");
	}
}
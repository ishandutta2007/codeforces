#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
stack<int> sk;
int a[maxn], x;
int sum, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = ans = 0;
		while(n--){
			scanf("%d", &x);
			if(!a[x]) sk.push(x), ++sum;
			++a[x];
		}
		while(!sk.empty()){
			ans = max(ans, min(a[sk.top()], sum - 1));
			ans = max(ans, min(a[sk.top()] - 1, sum));
			a[sk.top()] = 0;
			sk.pop();
		}
		printf("%d\n", ans);
	}
}
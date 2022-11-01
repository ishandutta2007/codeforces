#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
char s[maxn];
int ans = 0;
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		int ans = 0, x = 0, y = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == 'W') ans += x ? 2 : 1, x = 1;
			else x = 0;
		}
		x = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == 'L') x++;
			else break;
		}
		if(x == n){
			if(k){
				ans++, k--;
				ans += k * 2;
			}
			printf("%d\n", ans);
			continue;
		}
		for(int i = n;i;i--){
			if(s[i] == 'L') y++;
			else break;
		}
		v.clear();
		int sum = 0; 
		for(int i = x + 1;i <= n - y;i++){
			if(s[i] == 'W'){
				if(sum) v.push_back(sum);
				sum = 0;
			}else{
				sum++;
			}
		}
		sort(v.begin(), v.end());
		for(int i = 0;i < v.size() && k;i++){
			if(k >= v[i]){
				k -= v[i];
				ans += v[i] * 2 + 1;
			}else{
				ans += k * 2;
				k = 0;
			}
		}
		ans += 2 * min(k, x + y);
		printf("%d\n", ans);	
	}
}
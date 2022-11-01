#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n;
int a[maxn];
int cal(int i){
	if(i <= 1 || i >= n) return 0;
	return a[i] > a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1];
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int sum = 0, ans = 0;
		for(int i = 2;i < n;i++){
			sum += cal(i);
		}
		for(int i = 1;i <= n;i++){
			int cnt = 0, x = a[i];
			if(i > 1){
				cnt -= cal(i - 1) + cal(i) + cal(i + 1);
				a[i] = a[i - 1];
				cnt += cal(i - 1) + cal(i) + cal(i + 1);
				ans = min(ans, cnt);
				cnt = 0;
				a[i] = x;
			}
			if(i < n){
				cnt -= cal(i - 1) + cal(i) + cal(i + 1);
				a[i] = a[i + 1];
				cnt += cal(i - 1) + cal(i) + cal(i + 1);
				ans = min(ans, cnt);
				cnt = 0;
				a[i] = x;
			}
			if(i > 1 && i < n){
				cnt -= cal(i - 1) + cal(i) + cal(i + 1);
				a[i] = a[i - 1] + a[i + 1] >> 1;
				cnt += cal(i - 1) + cal(i) + cal(i + 1);
				ans = min(ans, cnt);
				cnt = 0;
				a[i] = x;
			}
			if(i > 1 && i < n){
				cnt -= cal(i - 1) + cal(i) + cal(i + 1);
				a[i] = (a[i - 1] + a[i + 1] + 1) >> 1;
				cnt += cal(i - 1) + cal(i) + cal(i + 1);
				ans = min(ans, cnt);
				cnt = 0;
				a[i] = x;
			}
			if(i > 1 && i < n){
				cnt -= cal(i - 1) + cal(i) + cal(i + 1);
				a[i] = max(a[i - 1], a[i + 1]) + 1;
				cnt += cal(i - 1) + cal(i) + cal(i + 1);
				ans = min(ans, cnt);
				cnt = 0;
				a[i] = x;
			}
			if(i > 1 && i < n){
				cnt -= cal(i - 1) + cal(i) + cal(i + 1);
				a[i] = min(a[i - 1], a[i + 1]) - 1;
				cnt += cal(i - 1) + cal(i) + cal(i + 1);
				ans = min(ans, cnt);
				cnt = 0;
				a[i] = x;
			}
			cnt -= cal(i - 1) + cal(i) + cal(i + 1);
			a[i] = 2e9;
			cnt += cal(i - 1) + cal(i) + cal(i + 1);
			ans = min(ans, cnt);
			cnt = 0;
			a[i] = x;
			
			cnt -= cal(i - 1) + cal(i) + cal(i + 1);
			a[i] = -2e9;
			cnt += cal(i - 1) + cal(i) + cal(i + 1);
			ans = min(ans, cnt);
			cnt = 0;
			a[i] = x;
		}
		printf("%d\n", sum + ans);
	}
}
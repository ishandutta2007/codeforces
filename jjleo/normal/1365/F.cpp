#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

map<pair<int, int>, int> mp;

int t;

int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		if((n & 1) && a[n / 2 + 1] != b[n / 2 + 1]){
			puts("No");
			continue;
		}
		mp.clear();
		for(int i = 1;i * 2 <= n;i++){
			mp[{min(a[i], a[n + 1 - i]), max(a[i], a[n + 1 - i])}]++;
		}
		bool suc = true;
		for(int i = 1;i * 2 <= n;i++){
			if(!mp[{min(b[i], b[n + 1 - i]), max(b[i], b[n + 1 - i])}]){
				suc = false;
				break;
			}
			mp[{min(b[i], b[n + 1 - i]), max(b[i], b[n + 1 - i])}]--;
		}
		puts(suc ? "Yes" : "No");
	}
}
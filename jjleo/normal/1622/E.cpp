#include <bits/stdc++.h>
#define maxn 10086

using namespace std;

int t, n, m;
int a[20];
char s[20][maxn];
int b[maxn], c[maxn];
int val[maxn];
vector<int> v[40];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0;i < n;i++) scanf("%d", &a[i]);
		for(int i = 0;i < n;i++) scanf("%s", s[i] + 1);
		int ans = 0;
		for(int i = 1;i <= m;i++) b[i] = i;
		for(int S = 0;S < (1 << n);S++){
			int sum = 0;
			for(int j = 1;j <= m;j++) val[j] = 0;
			for(int i = 0;i < n;i++){
				if(S & (1 << i)) sum += a[i];
				else sum -= a[i];
				for(int j = 1;j <= m;j++) if(s[i][j] == '1'){
					if(S & (1 << i)) val[j]--;
					else val[j]++;
				}
			}
			for(int i = 0;i <= n * 2;i++) v[i].clear();
			for(int j = 1;j <= m;j++) v[val[j] + n].push_back(j);
			int cnt = 0;
			for(int i = 0;i <= n * 2;i++){
				for(int j = 0;j < v[i].size();j++){
					c[v[i][j]] = ++cnt;
					sum += (i - n) * cnt;
				}
			}
			if(sum > ans){
				ans = sum;
				for(int i = 1;i <= m;i++) b[i] = c[i];
			}
		}
		for(int i = 1;i <= m;i++) printf("%d ", b[i]);puts("");
	}
}
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn]; 
int f[maxn][35];
int to[maxn];
int b[maxn];
int ans[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &f[i][0]);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int j = 1;j <= 30;j++) for(int i = 1;i <= n;i++) f[i][j] = f[f[i][j - 1]][j - 1];
	int pos = max_element(a + 1, a + 1 + n) - a;
	if(a[pos] == n){
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		return 0;
	}
	int cnt = 0;
	while(1){
		cnt++;
		bool tag = false;
		for(int j = pos - 1;j;j--) if(a[j] + 1 == a[pos]){
			tag = true;
			pos = j;
			break;
		}
		if(!tag) break;
	}
	cnt = (*max_element(a + 1, a + 1 + n) - n) / cnt;
	for(int i = 1;i <= n;i++){
		to[i] = i;
		for(int j = 0;j <= 30	;j++) if(cnt & (1 << j)) to[i] = f[to[i]][j];
	}
	for(int i = 1;i <= n;i++) b[i] = 1e9;
	for(int i = 1;i <= n;i++) b[to[i]] = min(b[to[i]], i);
	for(int i = 1;i <= n;i++) if(a[i] <= n && b[i] <= n) ans[b[i]] = a[i];
	set<int> st;
	for(int i = 1;i <= n;i++) st.insert(i);
	for(int i = 1;i <= n;i++) if(ans[i]) st.erase(ans[i]);
	for(int i = 1;i <= n;i++) if(!ans[i]){
		if(a[to[i]] > n) ans[i] = *st.begin();
		else ans[i] = *st.lower_bound(a[to[i]]);
		st.erase(ans[i]);
	}
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}
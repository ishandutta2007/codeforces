#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int a[maxn];
int p[maxn], cnt;
bool tag[maxn];
int last[maxn];
vector<int> v;
int f[maxn][25];
set<int> st;

int main(){
	scanf("%d", &t);
	for(int i = 2;i * i <= 1e7;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i * p[j] * i <= 1e7;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) break;
		}
	}
	while(t--){
		scanf("%d%d", &n, &k);
		v.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			for(int j = 1;j <= cnt;j++){
				int x = 0;
				while(a[i] % p[j] == 0){
					a[i] /= p[j], x++;
				}
				if(x & 1) a[i] *= p[j];
			}
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1;i <= n;i++) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) f[i][j] = 1e9;
		for(int i = 1;i <= v.size();i++) last[i] = 0;
		f[0][0] = 0;
		st.clear(), st.insert(0);
		for(int i = 1;i <= n;i++){
			if(last[a[i]]) st.insert(last[a[i]]);
			last[a[i]] = i;
			int cnt = 0;
			for(set<int>::reverse_iterator it = st.rbegin();it != st.rend() && cnt <= k + 1;++it, cnt++){
				for(int j = 0;j + cnt <= k;j++) f[i][j + cnt] = min(f[i][j + cnt], f[*it][j] + 1);
			}
		}
		int ans = 1e9;
		for(int i = 0;i <= k;i++) ans = min(ans, f[n][i]);
		printf("%d\n", ans);
	}
}
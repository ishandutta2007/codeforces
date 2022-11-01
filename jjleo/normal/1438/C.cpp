#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int t, n, m;
int a[maxn][maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		v.clear();
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				scanf("%d", &a[i][j]);
				v.push_back(a[i][j]);
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int k = v.size() - 1;~k;k--){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= m;j++){
					if(a[i][j] == v[k] && ((i + j - k) & 1)) a[i][j]++;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				printf("%d ", a[i][j]);
			}
			puts("");
		}
	}
}
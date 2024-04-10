#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int a[maxn];
bool b[105];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		memset(b, 0, sizeof(b)), v.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(!b[a[i]]) b[a[i]] = true, v.push_back(a[i]);
		}
		if(v.size() > k){
			puts("-1");
			continue;
		}
		for(int i = 1;i <= n && v.size() < k;i++) if(!b[i]) v.push_back(i);
		printf("%d\n", n * v.size());
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < v.size();j++){
				printf("%d ", v[j]);
			}
		}
		puts("");
	}
}
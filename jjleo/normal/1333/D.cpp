#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

int n, k;
char s[maxn];
int ans[maxn];
int cnt;
int tot;

vector<int> v[maxn];

int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	while(1){
		bool tag = false;
		++tot;
		for(int i = 1;i < n;i++){
			if(s[i] == 'R' && s[i + 1] == 'L'){
				tag = true;
				swap(s[i], s[i + 1]);
				v[tot].push_back(i);
				++i;
				++cnt;
			}
		}
		if(!tag) break;
		if(tot > k) return printf("-1"), 0;
		/*tag = false, ++tot;
		for(int i = n - 1;i;i--){
			if(s[i] == 'R' && s[i + 1] == 'L'){
				tag = true;
				swap(s[i], s[i + 1]);
				v[tot].push_back(i);
				--i;
			}
		}
		if(!tag) break;*/
	}
	tot--;
	if(cnt < k) return printf("-1"), 0;
	int x = k - tot;
	for(int i = 1;i <= tot;i++){
		while(x && v[i].size()){
			printf("%d %d\n", 1, v[i][v[i].size() - 1]);
			v[i].pop_back(), --x;
		}
		if(!v[i].size()) ++x;
		else{
			printf("%d ", v[i].size());
			for(int j = 0;j < v[i].size();j++) printf("%d ", v[i][j]);
			puts("");
		}
	}
	
	/*int len = cnt / k, j = 1;
	for(int i = 1;i < k;i++){
		int l = j + len - 1;
		printf("%d", len);
		while(j <= l) printf(" %d", ans[j++]);
		puts("");
	}
	printf("%d", cnt - j + 1);
	for(int i = j;i <= cnt;i++) printf(" %d", ans[i]);*/
}
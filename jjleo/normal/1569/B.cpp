#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int t, n;
char s[maxn];
char a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int cnt[3] = {0};
		for(int i = 1;i <= n;i++) cnt[s[i] - '0']++;
		if(cnt[2] && cnt[2] <= 2){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[i][j] = '=';
		vector<int> v;
		for(int i = 1;i <= n;i++) if(s[i] == '2') v.push_back(i);
		for(int i = 0;i < v.size();i++){
			int j = i + 1;
			if(j == v.size()) j = 0;
			a[v[i]][v[j]] = '+', a[v[j]][v[i]] = '-';
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) printf("%c", i == j ? 'X' : a[i][j]);
			puts("");
		}
	}
}
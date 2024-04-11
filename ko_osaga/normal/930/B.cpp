#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
typedef pair<int, int> pi;
typedef long long lint;

int n, vis[MAXN];
char str[MAXN];
int cnt[MAXN][26];

double solve(char c){
	memset(cnt, 0, sizeof(cnt));
	int tot = 0;
	for(int i=0; i<n; i++){
		if(str[i] == c){
			tot++;
			for(int j=0; j<n; j++){
				cnt[j][str[(i + j) % n] - 'a']++;
			}
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		int dist = 0;
		for(int j=0; j<26; j++) if(cnt[i][j] == 1) dist++;
		ans = max(ans, dist);
	}
	return 1.0 * ans / tot;
}

int main(){
	cin >> str;
	n = strlen(str);
	for(int i=0; i<n; i++){
		vis[str[i]]++;
	}
	double ans = 0;
	for(int i='a'; i<='z'; i++){
		if(vis[i]) ans += vis[i] * solve(i) / n;
	}
	printf("%.10f\n", ans);
}
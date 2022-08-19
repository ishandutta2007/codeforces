#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 1000005;

int n, m;
string str[MAXN];
vector<int> dp1[MAXN];
vector<int> dp2[MAXN];
char buf[MAXN];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%s", buf);
		str[i] = buf;
		dp1[i].resize(m);
		dp2[i].resize(m);
	}
	dp1[0][0] = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] == '#') continue;
			if(i && dp1[i-1][j]) dp1[i][j] = 1;
			if(j && dp1[i][j-1]) dp1[i][j] = 1;
		}
	}
	dp2[n-1][m-1] = 1;
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			if(str[i][j] == '#') continue;
			if(i+1<n && dp2[i+1][j]) dp2[i][j] = 1;
			if(j+1<m && dp2[i][j+1]) dp2[i][j] = 1;
		}
	}
	if(!dp2[0][0]){
		puts("0");
		return 0;
	}
	vector<int> cnt(n + m + 2);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(dp1[i][j] && dp2[i][j]) cnt[i+j]++;
		}
	}
	for(int i=1; i<n+m-2; i++){
		if(cnt[i] == 1){
			puts("1");
			return 0;
		}
	}
	puts("2");
}
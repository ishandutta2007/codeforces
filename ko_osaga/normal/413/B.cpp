#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, tab[20005][12], cnt1[20005], cnt2[12], q;

int main(){
	cin >> n >> m >> q;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d",&tab[i][j]);
		}
	}
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		cnt2[y]++;
		cnt1[x]--;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(tab[i][j]) cnt1[i] += cnt2[j];
		}
		printf("%d ", cnt1[i]);
	}
}
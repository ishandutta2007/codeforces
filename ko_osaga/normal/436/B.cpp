#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m, k;
int cnt[2005];

int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		char buf[2005];
		scanf("%s", buf);
		for(int j=0; j<m; j++){
			if(buf[j] == 'L'){
				if(j - i >= 0) cnt[j - i]++;
			}
			if(buf[j] == 'R'){
				if(j + i < m) cnt[j + i]++;
			}
			if(buf[j] == 'U' && (i % 2 == 0)){
				cnt[j]++;
			}
		}
	}
	for(int i=0; i<m; i++) printf("%d ", cnt[i]);
}
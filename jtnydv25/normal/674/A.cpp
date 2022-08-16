#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

const int N = 5005;
int cnt[N], a[N], ans[N];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	for(int i = 1; i <= n; i++){
		memset(cnt, 0, sizeof cnt);
		int mxi = 0, maxfreq = 0;
		for(int j = i; j <= n; j++){
			cnt[a[j]] ++;
			if(cnt[a[j]] > maxfreq || (cnt[a[j]] == maxfreq && a[j] < mxi)){
				mxi = a[j];
				maxfreq = cnt[a[j]];
			}
			ans[mxi] ++;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
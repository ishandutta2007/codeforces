#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
typedef pair<int, int> pi;
typedef long long lint;

int n, a[MAXN];
int cnt[MAXN], dep[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=2; i<=n; i++){
		scanf("%d",&a[i]);
		dep[i] = dep[a[i]] + 1;
	}
	for(int i=1; i<=n; i++) cnt[dep[i]]++;
	int ans = 0;
	for(int i=0; i<=n; i++) if(cnt[i] & 1) ans++;
	cout << ans << endl;
}
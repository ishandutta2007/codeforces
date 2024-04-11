#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[200005];
int b[200005];
bool vis[200005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&b[i]);
	}
	if(count(b+1, b+n+1, 1) % 2 == 0) ans++;
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i] = 1;
			for(int j=a[i]; j!=i; j=a[j]){
				vis[j] = 1;
			}
			cnt++;
		}
	}
	if(cnt == 1) cnt = 0;
	cout << ans + cnt;
}
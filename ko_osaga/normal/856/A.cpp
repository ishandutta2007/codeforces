#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 1e9 + 7;
const int MAXN = 105;

int n, a[MAXN];
int chk[1000005];

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		for(int i=0; i<n; i++){
			for(int j=0; j<i; j++) chk[a[i]- a[j]] = 1;
		}
		for(int i=1; i<=1000000; i++){
			int ok = 1;
			for(int j=i; j<1000000; j+=i){
				if(chk[j]){
					ok = 0;
					break;
				}
			}
			if(ok){
				puts("YES");
				for(int j=0; j<n; j++) printf("%d ", i * j + 1);
				puts("");
				break;
			}
		}
		memset(chk, 0, sizeof(chk));
	}
}
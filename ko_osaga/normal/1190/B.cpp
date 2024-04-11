#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000005;
 
int n, m, k, a[MAXN],b[MAXN];
 
int main(){
	scanf("%d",&n);
	set<int> s;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	sort(a, a + n);
	if((int)s.size() <= n - 2){
		puts("cslnb");
		return 0;
	}
	if((int)s.size() == n - 1){
		for(int i=1; i<n; i++){
			if(a[i]== a[i-1]){
				a[i-1]--;
				if(i > 1 && a[i-1] == a[i-2]){
					puts("cslnb");
					return 0;
				}
				if(a[i - 1] < 0){
					puts("cslnb");
					return 0;
				}
				a[i-1]++;
			}
		}
	}
	lint sum = 1ll * n * (n - 1) / 2;
	lint acc = accumulate(a, a + n, 0ll);
	if(sum % 2 == acc % 2) puts("cslnb");
	else puts("sjfnb");
}
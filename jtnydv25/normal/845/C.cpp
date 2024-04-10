#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 2e5 + 10;
int l[N], r[N];
pair<int, int> P[N];
#define F first
#define S second
int main(){
	int t = 1, n;
	// sd(t);
	while(t--){
		sd(n);
		for(int i = 0; i < n; i++) sd(l[i]), sd(r[i]), P[i] = {l[i], r[i]};
		sort(P, P + n);
		int present = 0;
		r[0] = r[1] = -1;
		for(int i = 0; i < n; i++){
			int L = P[i].F, R = P[i].S;
			if(L <= r[present]){
				present ^= 1;
				if(L <= r[present]){
					printf("NO");
					return 0;
				}
				r[present] = R;
			}
			else{
				r[present] = R;
			}
		}
		printf("YES");
	}
}
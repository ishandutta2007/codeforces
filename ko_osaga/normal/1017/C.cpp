#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;

// Jihoon JOA
int Do(lint n, lint a, lint b){
    if(a+b-1 > n){
    	assert(0);
    }
    if(a * b < n){
    	assert(0);
    }
    for(long long i=n-a+1;i<=n;i++){
        printf("%lld ", i);
    }
    long long nn = n-a;
    n = n-a;
    for(long long i=b-2;i>=0;i--){
        long long gae;
        if(i < (nn % (b-1))){
            gae = nn / (b-1) + 1;
        }else{
            gae = nn / (b-1);
        }
        for(long long j=n-gae+1;j<=n;j++){
            printf("%lld ", j);
        }
        n -= gae;
    }
    printf("\n");
    return 0;
}

int main(){
	int n;
	cin >> n;
	int cnt = 1;
	pi ans(1e9, 1e9);
	for(int i=n; i; i--){
		while(1ll * i * cnt < n) cnt++; 
		if(i + cnt - 1 <= n){
			ans = min(ans, pi(i + cnt, i));
		}
	}
	assert(ans.first < 1e8);
	Do(n, ans.first - ans.second, ans.second);
}
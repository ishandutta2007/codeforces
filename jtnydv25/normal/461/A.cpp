#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int n;
int A[300005];
multiset<int> ms;
long long ans = 0;
int main(){
	int x;
	sd(n);
	long long sm = 0;
	for(int i = 1; i <= n; i++){
		sd(x);
		ms.insert(x);
		sm += x;
	}
	while(ms.size() > 1){
		ans += sm;
		ans += *ms.begin();
		sm -= *ms.begin();
		ms.erase(ms.begin());
	}
	ans += *ms.begin();
	printf("%lld", ans);
}
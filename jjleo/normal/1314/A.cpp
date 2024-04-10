#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
pair<int, int> a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i].first);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i].second);
	sort(a + 1, a + 1 + n);
	int now = 0, x = 0;
	multiset<int> st;
	long long ans = 0, sum = 0;
	while(1){
		if(st.empty()){
			if(x == n) break;
			now = a[x + 1].first;
		}
		while(x < n && a[x + 1].first == now) x++, sum += a[x].second, st.insert(a[x].second);
		sum -= *st.rbegin(), st.erase(st.find(*st.rbegin()));
		ans += sum;
		now++;
	}
	printf("%lld", ans);
}
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

bool check(int k){
	multiset<int> st;
	for(int i = 1;i <= n;i++) st.insert(a[i]);
	while(k){
		if(st.empty() || *st.begin() > k) return false;
		st.erase(prev(st.upper_bound(k)));
		if(!st.empty()) st.erase(st.begin());
		k--;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = n;~i;i--) if(check(i)){
			printf("%d\n", i);
			break;
		}
	}
}
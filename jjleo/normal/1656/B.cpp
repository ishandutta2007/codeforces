#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, k;
int a[maxn];

bool solve(){
	scanf("%d%d", &n, &k);
	multiset<int> st;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), st.insert(a[i]);
	for(int i = 1;i <= n;i++){
		st.erase(st.find(a[i]));
		if(st.find(k + a[i]) != st.end()) return true;
		st.insert(a[i]);
	}
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}
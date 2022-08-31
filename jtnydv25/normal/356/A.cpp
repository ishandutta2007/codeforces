#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int N = 300005;
int l[N], r[N], x[N];
vector<int> deletions;
int lost[N];
set<int> st;
int main(){
	int n, m;
	sd(n); sd(m);
	for(int i = 1; i <= n; i++) st.insert(i);
	for(int i = 1; i <= m; i++){
		sd(l[i]);
		sd(r[i]);
		sd(x[i]);
		auto it = st.lower_bound(l[i]);
		deletions.clear();
		while(it != st.end() && (*it) <= r[i]){
			if((*it) != x[i]) deletions.push_back(*it);
			it++;
		}
		for(int t : deletions) lost[t] = x[i], st.erase(t);
	}
	for(int i = 1; i <= n; i++) printf("%d ", lost[i]);
}
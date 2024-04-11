#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

map<lint, lint> mp;

void add(lint s, lint e, lint x){
	if(s == e) return;
	if(s < e) swap(s, e);
	mp[s] += x;
	add(s/2, e, x);
}

lint query(lint s, lint e){
	if(s == e) return 0;
	if(s < e) swap(s, e);
	return query(s/2, e) + mp[s];
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			lint s, e, x;
			cin >> s >> e >> x;
			add(s, e, x);
		}
		else{
			lint s, e;
			cin >> s >> e;
			cout << query(s, e) << endl;
		}
	}
}
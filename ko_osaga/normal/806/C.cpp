#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n;
lint a[100005];
int cnt[55];
int needm[55];
int sum = 0;

void add(lint x){
	sum++;
	int stp = 0;
	for(int j=0; j<50; j++){
		if(x >= (2ll << j)) stp = j+1;
	}
	needm[stp]++;
}

bool matching(int l){
	if(sum > l) return 0;
	int tmp = 0;
	int prv = 0;
	for(int i=49; i>=0; i--){
		tmp += needm[i];
		if(tmp > cnt[i]) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	set<lint> s;
	for(int i=0; i<50; i++){
		lint k = (1ll << i);
		cnt[i] = upper_bound(a, a+n, k) - lower_bound(a, a+n, k);
		s.insert(k);
	}
	for(int i=0; i<n; i++){
		if(s.find(a[i]) == s.end()) add(a[i]);
	}
	vector<int> ans;
	int cur = cnt[0];
	for(int i=1; i<50; i++){
		while(cur < cnt[i]){
			add(1ll << i);
			cnt[i]--;
		}
		cur = cnt[i];
	}
	while(cnt[0] > 0){
		int j = cnt[0];
		if(matching(j)) ans.push_back(j);
		for(int k=0; k<50; k++){
			if(cnt[k] == j){
				cnt[k]--;
				add(1ll << k);
			}
		}
	}
	if(ans.empty()){
		cout << -1;
		return 0;
	}
	reverse(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
}
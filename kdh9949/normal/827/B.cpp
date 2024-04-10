#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, sn, k, cur;
queue<int> q, nq;
vector<pii> ans;
vector<int> e[200010];

pii f(int x, int p){
	pii ret = {0, x};
	for(auto &i : e[x]){
		if(i == p) continue;
		pii t = f(i, x);
		ret = max(ret, {t.first + 1, t.second});
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	sn = n;
	n -= k;
	for(int i = 1; i <= k; i++) q.push(i);
	cur = k + 1;
	while(true){
		if(n <= k + 1){
			if(n == 1){
				while(!q.empty()){
					ans.push_back({q.front(), sn});
					q.pop();
				}
				break;
			}
			for(int i = 0; i < n - 1; i++){
				ans.push_back({q.front(), cur});
				ans.push_back({cur++, sn});
				q.pop();
			}
			while(!q.empty()){
				ans.push_back({q.front(), sn});
				q.pop();
			}
			break;
		}
		while(!q.empty()){
			ans.push_back({q.front(), cur});
			q.pop();
			nq.push(cur++);
		}
		swap(q, nq);
		n -= k;
		k = q.size();
	}
	for(auto &i : ans){
		e[i.first].push_back(i.second);
		e[i.second].push_back(i.first);
	}
	printf("%d\n", f(f(1, 0).second, 0).first);
	for(auto &i : ans) printf("%d %d\n", i.first, i.second);
}
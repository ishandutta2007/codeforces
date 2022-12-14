#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)3e5 + 4;
int N, k;
int l[NS];
int pr[NS], chi[NS], prs[NS];
int chk[NS], cnt[NS], pcnt[NS];

void dfs(int x){
	chk[x] = 1;
	if(pr[x] != x){
		if(chk[pr[x]]){
			cout << 0;
			exit(0);
		}
		dfs(pr[x]);
	}
}

void dfs2(int x){
	chk[x] = 1;
	if(chi[x] != x){
		if(chk[chi[x]]){
			cout << 0;
			exit(0);
		}
		dfs2(chi[x]);
	}
}

int fd(int x){
	return (x == pr[x] ? x : pr[x] = fd(pr[x]));
}

priority_queue<pair<int, int>> pq;
vector<int> ans;
int did[NS];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> k;
	for(int i = 1; i <= N; ++i){
		cin >> l[i];
		++cnt[l[i]];
		pr[i] = i; chi[i] = i;
	}
	for(int i = 1; i <= k; ++i){
		int a, b; cin >> a >> b;
		pr[b] = a; chi[a] = b; prs[b] = a;
	}
	for(int i = 1; i <= N; ++i){
		if(!chk[i]){
			dfs(i);
			dfs2(i);
		}
	}
	for(int i = 1; i <= N; ++i){
		if(fd(i) == fd(l[i])){
			--cnt[l[i]];
		}
	}
	for(int i = 1; i <= N; ++i){
		pcnt[fd(i)] += cnt[i];
	}
	for(int i = 1; i <= N; ++i){
		if(fd(i) == i){
			pq.push({-pcnt[i], i});
		}
	}
	memset(chk, 0, sizeof(chk));
	while(!pq.empty()){
		while(!pq.empty() && chk[pq.top().second]){
			pq.pop();
		}
		if(pq.empty()){
			break;
		}
		auto top = pq.top(); pq.pop();
		chk[top.second] = 1;
		//cout << top.first << ' ' << top.second << '\n';
		if(top.first != 0){
			cout << 0;
			return 0;
		}
		int r = top.second;
		while(1){
			if(l[r]){
				--pcnt[fd(l[r])];
				pq.push({-pcnt[fd(l[r])], fd(l[r])});
			}
			if(chi[r] != r){
				r = chi[r];
			}
			else{
				break;
			}
		}
		while(1){
			ans.push_back(r);
			if(prs[r]){
				r = prs[r];
			}
			else{
				break;
			}
		}
	}
	for(int i = (int)ans.size() - 1; i >= 0; --i){
		if(l[ans[i]] && !did[l[ans[i]]]){
			cout << 0;
			return 0;
		}
		did[ans[i]] = 1;
	}
	for(int i = (int)ans.size() - 1; i >= 0; --i){
		cout << ans[i] << ' ';
	}
	return 0;
}
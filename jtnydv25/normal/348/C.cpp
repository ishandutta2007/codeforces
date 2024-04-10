#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define sd(x) scanf("%d", &(x));
const int N = 100005;
const int SQN = 305;
int sz[N], perm[N], iperm[N];
ll curr[N];
ll a[N];
bool cmp(int i, int j){
	return sz[i] > sz[j];
}
vector<int> positions[N];
int intersection[SQN][N];
bool present[SQN][N];
ll BIG[SQN];

int n, m, q;
void upd(int i, ll x){
	if(iperm[i] < SQN){
		for(int j = 1; j < SQN && j <= m; j++)
			curr[perm[j]] += intersection[iperm[i]][perm[j]] * x;
		BIG[iperm[i]] += x;
	}
	else{
		for(int ind : positions[i]) a[ind] += x;
		for(int j = 1; j < SQN && j <= m; j++)
			curr[perm[j]] += intersection[j][i] * x;
	}
}

ll get(int i){
	if(iperm[i] < SQN) return curr[i];
	ll ans = curr[i];
	for(int ind : positions[i]) ans += a[ind];
	for(int j = 1; j <= m && j < SQN; j++){
		ans += BIG[j] * intersection[j][i];
	}
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= m; i++){
		cin >> sz[i];
		for(int j = 1; j <= sz[i]; j++){
			int pos;
			cin >> pos;
			positions[i].push_back(pos);
			curr[i] += a[pos];
		}		
		perm[i] = i;
	}
	memset(a, 0, sizeof a);
	sort(perm + 1, perm + m + 1, cmp);
	for(int i = 1; i <= m; i++) iperm[perm[i]] = i;
	for(int i = 1; i <= m && i < SQN; i++){
		int ind = perm[i];
		for(auto it : positions[ind]) present[i][it] = 1;
		for(int j = 1; j <= m; j++){
			for(int x : positions[j]) if(present[i][x]) intersection[i][j]++;
		}
	}
	while(q--){
		char c;
		cin >> c;
		if(c=='?'){
			int k;
			cin >> k;
			cout << get(k) << "\n";
			// printf("%lld\n", get(k));
		}
		else{
			ll x;
			int k;
			cin >> k >> x;
			upd(k, x);
		}
	}
}
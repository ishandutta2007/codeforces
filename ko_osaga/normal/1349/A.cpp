#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 200005;

int low[MAXN];
int n, a[MAXN];
map<int, int> v[MAXN];

int main(){
	for(int i=2; i<MAXN; i++){
		for(int j=i; j<MAXN; j+=i){
			if(!low[j]) low[j] = i;
		}
	}
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		for(int j=a[i]; j>1; j/=low[j]){
			v[low[j]][i]++;
		}
	}
	lint sex = 1;
	for(int i=2; i<MAXN; i++){
		if(sz(v[i]) <= n - 2) continue;
		vector<int> ans;
		for(auto &j : v[i]){
			ans.push_back(j.second);
		}
		while(sz(ans) < n) ans.push_back(0);
		sort(all(ans));
		for(int j=0; j<ans[1]; j++){
			sex *= i;
		}
	}
	cout << sex << endl;
}
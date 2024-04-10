#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
string s;
map<string, vector<string> > mp;
ll ans;

int son[maxn][26], cnt;
vector<int> v[maxn];
int lcp[maxn], sk[maxn], top;

void solve(vector<string> a){
	ans += (2 - 1337ll) * (a.size() * (a.size() - 1) / 2);
	sort(a.begin(), a.end(), greater<string>());
	for(int i = 1;i <= cnt;i++) memset(son[i], 0, sizeof(son[i])), v[i].clear();cnt = 1;
	vector<vector<int> > b, c;
	for(int i = 0;i < a.size();i++){
		vector<int> w;
		for(int j = a[i].length() - 1;~j;j--){
			if(w.empty() || a[i][j] > a[i][j + 1]) w.push_back(j);
			else w.push_back(w.back());
		}
		reverse(w.begin(), w.end());
		b.push_back(w);
		int now = 1;
		v[now].push_back(i);
		w.clear(), w.push_back(now); 
		for(int j = a[i].length() - 1;~j;j--){
			if(!son[now][a[i][j] - 'a']) son[now][a[i][j] - 'a'] = ++cnt;
			v[now = son[now][a[i][j] - 'a']].push_back(i);
			w.push_back(now);
		}
		reverse(w.begin(), w.end());
		c.push_back(w);
		if(i){
			lcp[i] = 0;
			for(int j = 0;j < a[i].length();j++){
				if(a[i][j] ^ a[i - 1][j]) break;
				lcp[i] = j + 1;
			}
		}
	}
	top = 0;
	for(int i = 1;i < a.size();i++){
		while(top && lcp[i] <= lcp[sk[top]]) top--;
		sk[++top] = i;
		for(int j = top;j;j--){
			if(lcp[sk[j]] == a[i].length()){
				ans += (0 - 2) * (sk[j] - sk[j - 1]);
				continue;
			}
			int id = c[i][b[i][lcp[sk[j]]] + 1];
			ans += (0 - 1) * (upper_bound(v[id].begin(), v[id].end(), sk[j] - 1) - lower_bound(v[id].begin(), v[id].end(), sk[j - 1]));
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		cin >> s;
		string S = s;
		sort(S.begin(), S.end());
		mp[S].push_back(s);
	}
	ans = 1337ll * n * (n - 1) / 2;
	for(map<string, vector<string> >::iterator it = mp.begin();it != mp.end();++it) solve(it->second);
	printf("%lld", ans);
}
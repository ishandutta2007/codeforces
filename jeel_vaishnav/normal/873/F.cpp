#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 2e18

const int N = 2e5 + 5;


// 1-based index, sz : integer array from string [a..z -> 1..m], len: size of sz
int sa[N], wa[N], wb[N], cnt[N], rankOf[N], lcp[N];
void getSA(int *sz, int len){
    int *x = wa, *y = wb, m = 26;
    for (int i = 1; i <= len; i++) cnt[x[i] = sz[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = len; i; i--) sa[cnt[x[i]]--] = i;
    for (int h = 1; h <= len; h <<= 1){
        int pos = 0;
        for (int i = len - h + 1; i <= len; i++) y[++pos] = i;
        for (int i = 1; i <= len; i++) if (sa[i] > h) y[++pos] = sa[i] - h;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= len; i++) cnt[x[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = len; i; i--) sa[cnt[x[y[i]]]--] = y[i];
        swap(x, y); pos = 0; x[sa[1]] = ++pos;
        for (int i = 2; i <= len; i++) 
          x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + h] == y[sa[i - 1] + h] ? pos : ++pos;
        m = pos;
        if (m == len) break;
    }
}
void getLcp(int *sz, int len){
    for (int i = 1; i <= len; i++) rankOf[sa[i]] = i;
    int k = 0;
    for (int i = 1; i <= len; i++){
    	if(rankOf[i] == 1) {k = 0; continue;}
      if (k) k--;
      int p = sa[rankOf[i] - 1];
      while (sz[p + k] == sz[i + k]) k++;
      lcp[rankOf[i]] = k;
    }
}

int par[N], dsuSize[N], allowed[N];
int score = 0;
int findSet(int i) {
	if(par[i] == i)
		return i;
	par[i] = findSet(par[i]);
	return par[i];
}
void dsuUnion(int i, int j, int clcp) {
	i = findSet(i);
	j = findSet(j);

	if(i != j) {
		if(dsuSize[i] < dsuSize[j]) {
			int temp = i;
			i = j;
			j = temp;
		}

		par[j] = i;
		dsuSize[i] += dsuSize[j];
		allowed[i] += allowed[j];
		// cout << i << " " << j << " " << allowed[i] << " " << clcp << endl;
		score = max(score, allowed[i] * clcp);
	}
}



signed main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n;
	cin >> n;

	string s, mask;
	cin >> s >> mask;

	int a[s.length() + 1];
	for(int i = 1; i <= n; ++i) {
		a[i] = (s[n - i] - 'a') + 1;
	}

	getSA(a, n);
	getLcp(a, n);

	for(int i = 0; i < n; ++i)
		par[i] = i;
	for(int i = 0; i < n; ++i)
		dsuSize[i] = 1;
	for(int i = 0; i < n; ++i) {
		int index = sa[i + 1];
		if(mask[s.length() - index] == '0') {
			allowed[i] = 1;
		} else {
			allowed[i] = 0;
		}
	}

	vector<pair<int, int>> pairs(n - 1);
	for(int i = 2; i <= n; ++i) {
		pairs[i - 2] = make_pair(lcp[i], i - 1);
	}

	for(int i = n - 1; i >= 0; --i) {
		if(mask[i] == '0') {
			score = i + 1;
			break;
		}
	}

	sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
	for(auto p : pairs) {
		dsuUnion(p.second - 1, p.second, p.first);
	}

	cout << score << endl;

	return 0;
}
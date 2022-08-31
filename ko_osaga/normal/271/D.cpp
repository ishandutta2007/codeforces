#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

char str[1505], ban[27];
int psum[1505], lcp[1505][1505], n, k;
int sfx[1505][1505];

int solve(int l, vector<int> &v){
	sort(v.begin(), v.end(), [&](const int &a, const int &b){
		return sfx[a][b];
	});
	int ret = 1;
	for(int i=1; i<v.size(); i++){
		if(lcp[v[i-1]][v[i]] < l) ret++;
	}
	return ret;
}

int main(){
	cin >> (str + 1) >> ban;
	cin >> k;
	n = strlen(str+1);
	for(int i=1; i<=n; i++){
		psum[i] = psum[i-1] + (ban[str[i]-'a'] == '0');
	}
	vector<int> v[1505];
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(psum[j] - psum[i-1] <= k){
				v[j-i+1].push_back(i);
			}
		}
	}
	for(int i=n; i; i--){
		for(int j=n; j; j--){
			if(str[i] == str[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
			else lcp[i][j] = 0;
			if(str[i] != str[j]) sfx[i][j] = (str[i] < str[j]);
			else sfx[i][j] = sfx[i+1][j+1];
		}
	}
	int ret = 0;
	for(int i=1; i<=n; i++){
		if(!v[i].empty()) ret += solve(i, v[i]);
	}
	cout << ret;
}
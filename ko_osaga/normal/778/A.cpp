#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

string s, t;
int a[222222];

bool trial(int l){
	int chk[200005] = {};
	for(int i=0; i<l; i++) chk[a[i] - 1] = 1;
	string tmp;
	for(int i=0; i<s.size(); i++){
		if(!chk[i]) tmp.push_back(s[i]);
	}
	int idx = 0;
	for(int i=0; i<t.size(); i++){
		while(idx < tmp.size() && tmp[idx] != t[i]) idx++;
		if(idx == tmp.size()) return 0;
		idx++;
	}
	return 1;
}

int main(){
	cin >> s >> t;
	for(int i=0; i<s.size(); i++) cin >> a[i];
	int st = 0, ed = s.size();
	while(st != ed){
		int m = (st+ed+1)/2;
		if(trial(m)) st = m;
		else ed = m-1;
	}
	cout << st;
}
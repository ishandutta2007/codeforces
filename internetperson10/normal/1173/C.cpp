#include <bits/stdc++.h>

using namespace std;

bool inhand[200001];
queue<int> pile;

int main() {
	ios::sync_with_stdio(false);
	int n, curr=1, ans=0, ub=0;
	bool cp=false;
	cin >> n;
	for(int a=0; a<n; a++) {
		int c;
		cin >> c;
		if(c>0) {
			inhand[c]=true;
		}
	}
	for(int a=0; a<n; a++) {
		int c;
		cin >> c;
		pile.push(c);
		if(c==curr) {
			curr++;
			cp=true;
		}
		else {
			cp=false;
			curr=1;
		}
		if(c>0) ub=max(ub, a-c+3);
	}
	while(true) {
		if(curr==n+1) break;
		ans++;
		int c = pile.front(); pile.pop();
		if(inhand[curr] && (ans>=ub || cp)) {
			inhand[curr]=false;
			pile.push(curr);
			curr++;
			ub++;
		}
		else {
			curr = 1;
			pile.push(0);
		}
		if(c>0) inhand[c]=true;
	}
	cout << ans << '\n';
}
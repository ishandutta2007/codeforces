#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 200005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<lint, lint>;

int main(){
	int n; cin >> n;
	set<int> s;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		s.insert(x);
	}
	int cnt = 0;
	while(sz(s)){
		int pos = *s.begin();
		for(int j=1; j<=100; j++){
			if(s.find(j * pos) != s.end()){
				s.erase(j * pos);
			}
		}
		cnt++;
	}
	cout << cnt << endl;
}
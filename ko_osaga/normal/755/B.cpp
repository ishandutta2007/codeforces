#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

set<string> s;
int n, m;
int crs;

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		s.insert(str);
	}
	for(int i=0; i<m; i++){
		string str;
		cin >> str;
		if(s.find(str) != s.end()) crs++;
	}
	while(1){
		if(crs) crs--;
		else if(n) n--;
		else{
			puts("NO");
			return 0;
		}
		if(crs) crs--;
		else if(m) m--;
		else{
			puts("YES");
			return 0;
		}
	}
}
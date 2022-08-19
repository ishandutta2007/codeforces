#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, k, a[55];
string s[55];

int main(){
	cin >> n >> k;
	for(int i=1; i<=k-1; i++) a[i] = i;
	int cnt = k-1;
	for(int i=k; i<=n; i++){
		string s;
		cin >> s;
		if(s == "YES") a[i] = ++cnt;
		else a[i] = a[i-k+1];
	}
	for(int i=0; i<26; i++){
		s[i+1].push_back('A' + i);
	}

	for(int i=0; i<26; i++){
		s[i+27].push_back('A');
		s[i+27].push_back('a' + i);
	}
	for(int i=1; i<=n; i++){
		printf("%s ", s[a[i]].c_str());
	}
}
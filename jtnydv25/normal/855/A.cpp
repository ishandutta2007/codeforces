#include <bits/stdc++.h>
using namespace std;
set<string> st;
int main(){
	int n;
	cin >> n;
	string s;
	for(int i = 1;i <= n; i++){
		cin >> s;
		if(st.count(s)){
			cout << "YES\n";
		}
		else cout << "NO\n";
		st.insert(s);
	}
}
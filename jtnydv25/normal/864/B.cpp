#include <bits/stdc++.h>
using namespace std;
string s;

inline int getDistinct(int a, int b){
	set<int> st;
	for(int i = a;i <= b; i++) st.insert(s[i] - 'a');
	return st.size();
}
int main(){
	int m; cin >> m;
	cin >> s;
	int i = 0, n = s.length();
	int mx = 0;
	while(i < n){
		while(i < n && s[i] - 'a' < 0) i++;
		int j = i;
		while(i < n && s[i] - 'a' >= 0) i++;
		mx = max(mx, getDistinct(j, i - 1));
	}
	cout << mx << endl;
}
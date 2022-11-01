#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
string s[maxn];

bool solve(){
	scanf("%d", &n);
	char ss[10];
	for(int i = 1;i <= n;i++) scanf("%s", ss), s[i] = ss;
	for(int i = 1;i <= n;i++){
		if(s[i].length() == 1) return true;
		if(s[i].length() == 2 && s[i][0] == s[i][1]) return true;
		if(s[i].length() == 3 && s[i][0] == s[i][2]) return true; 
	}
	set<string> st;
	for(int i = n;i;i--){
		if(st.find(s[i]) != st.end()) return true;
		string x = s[i];
		reverse(x.begin(), x.end());
		st.insert(x);
		if(x.length() == 3) st.insert(x.substr(0, 2));
	}
	st.clear();
	for(int i = n;i;i--){
		if(st.find(s[i]) != st.end()) return true;
		string x = s[i];
		reverse(x.begin(), x.end());
		st.insert(x);
	}
	reverse(s + 1, s + 1 + n);
	for(int i = 1;i <= n;i++) reverse(s[i].begin(), s[i].end());
	st.clear();
	for(int i = n;i;i--){
		if(st.find(s[i]) != st.end()) return true;
		string x = s[i];
		reverse(x.begin(), x.end());
		st.insert(x);
		if(x.length() == 3) st.insert(x.substr(0, 2));
	}
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}
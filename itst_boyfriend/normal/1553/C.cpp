#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int Q; string s; int ans;

void getans(string str){
	int v[2] = {0,0};
	for(int i = 0 ; i < 10 ; ++i){
		int lft0 = (10 - i) / 2 , lft1 = (11 - i) / 2;
		if(v[0] + lft0 < v[1] || v[1] + lft1 < v[0]){ans = min(ans , i); break;}
		v[i & 1] += str[i] - '0';
	}
}

void search(int x , string str){
	if(x == 10) return getans(str);
	if(s[x] != '1'){str.push_back('0'); search(x + 1 , str); str.pop_back();}
	if(s[x] != '0'){str.push_back('1'); search(x + 1 , str);}
}

int main(){
	for(cin >> Q ; Q ; --Q){cin >> s; ans = 10; search(0 , ""); cout << ans << endl;}
	return 0;
}
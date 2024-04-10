#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

string s;

int chk(int i, int j){
	int x =0, y = 0;
	for(int k = i; k <= j; k++){
		if(s[k] == 'L') x--;
		else if(s[k] == 'R') x++;
		else if(s[k] == 'U') y--;
		else y++;
	}
	return (x == 0 && y == 0);
}

int main(){
	int ans = 0;
	cin >> ans >> s;
	ans = 0;
	for(int i = 0; i < s.length(); i++)
		for(int j = i + 1; j < s.length(); j++) ans += chk(i, j);
	cout << ans;
}
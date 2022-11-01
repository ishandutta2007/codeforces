#include<bits/stdc++.h>
using namespace std;
bool vis[26];
int main(){
	int n;
	string s;
	cin >> n;
	if(n < 26)	cout << "NO";
	else{
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] >= 'A' && s[i] <= 'Z')
				vis[s[i] - 'A'] = true;
			else
				vis[s[i] - 'a'] = true;
		for(int i = 0 ; i < 26 ; i++)
			if(!vis[i])
			{
				cout << "NO";
				return 0;
			}
		cout << "YES";
	}
	return 0;
}
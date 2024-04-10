#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , m;
	string s , sbef = "\0";
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> s;
		string s1 = string(m , s[0]);
		if(s != s1 || sbef[0] == s[0])
		{
			cout << "NO";
			return 0;
		}
		sbef = s;
	}
	cout << "YES";
	return 0;
}
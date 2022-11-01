#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int num = 0;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] >= 'a' && s[i] <= 'z')    num++;
	if(num == 0 || (num == 1 && s[0] >= 'a'))
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] >= 'a' && s[i] <= 'z')
				cout << (char)(s[i] - 32);
			else
				cout << (char)(s[i] + 32);
	else
		cout << s;
	return 0;
}
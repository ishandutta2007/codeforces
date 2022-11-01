#include<bits/stdc++.h>
using namespace std;
int main(){
	int nLow = 0 , nUp = 0;
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] >= 'a' && s[i] <= 'z')	nLow++;
		else	nUp++;
	if(nLow >= nUp)
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] >= 'A' && s[i] <= 'Z')
				cout << char(s[i] + 32);
			else
				cout << s[i];
	else
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] >= 'a' && s[i] <= 'z')
				cout << char(s[i] - 32);
			else
				cout << s[i];
	return 0;
}
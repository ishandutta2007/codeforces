#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	if(n % 3 == 0)
		for(int i = 0 ; i < n / 3 ; i++)
		{
			if(i)	cout << '-';
			for(int j = 0 ; j < 3 ; j++)
				cout << s[i * 3 + j];
		}
	else
		if(n % 2 == 0)
			for(int i = 0 ; i < n / 2 ; i++)
			{
				if(i)	cout << '-';
				for(int j = 0 ; j < 2 ; j++)
					cout << s[i * 2 + j];
			}
		else
		{
			for(int i = 0 ; i < n / 2 - 1 ; i++)
			{
				if(i)	cout << '-';
				for(int j = 0 ; j < 2 ; j++)
					cout << s[i * 2 + j];
			}
			cout << '-';
			cout << s[s.size() - 3] << s[s.size() - 2] << s[s.size() - 1];
		}
	return 0;
}
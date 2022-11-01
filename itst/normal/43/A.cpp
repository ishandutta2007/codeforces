#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , numa = 0 , numb = 0;
	string s1 = "\0" , s2 = "\0";
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		string s;
		cin >> s;
		if(s1 == "\0")
		{
			s1 = s;
			numa++;
		}
		else
			if(s == s1)
				numa++;
			else
			{
				s2 = s;
				numb++;
			}
	}
	if(numa > numb)	cout << s1;
	else	cout << s2;
	return 0;
}
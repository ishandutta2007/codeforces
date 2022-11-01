#include<bits/stdc++.h>
using namespace std;
int main(){
	int m , n;
	string s;
	for(cin >> m >> n >> s ; n ; n--)
	{
		int a , b;
		char c , d;
		cin >> a >> b >> c >> d;
		for(int i = a - 1 ; i <= b - 1 ; i++)
			if(s[i] == c)
				s[i] = d;
	}
	cout << s;
	return 0;
}
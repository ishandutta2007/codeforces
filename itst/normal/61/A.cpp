#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1 , s2;
	cin >> s1 >> s2;
	for(int i = 0 ; i < s1.size() ; i++)
		if(s2[i] == '1')
			if(s1[i] == '1')
				s1[i]--;
			else
				s1[i]++;
	cout << s1;
	return 0;
}
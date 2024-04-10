#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int i=0,x=0;
	while (i+1<s.size()){
		if (s[i]==s[i+1]){
			s.erase(i,2);
			i-=2;
			i=max(-1,i);
			x++;
		}
		i++;
	}
	if (x%2){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}
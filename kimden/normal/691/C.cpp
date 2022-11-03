#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	int delim;
	cin >> s;
	int f = s.find_first_not_of('0',0);
	int g;
	s = s.substr(f,s.length()-f);
	delim = s.find('.',0);
	if(delim==string::npos){
		delim = s.length();
		s += '.';
	}
	if(delim==0){
		f = s.find_first_not_of('0',1);
		s = s.substr(f,s.length()-f);
		g = s.find_last_not_of('0',s.length());
		s = s.substr(0,g+1);
		cout << s[0];
		if(s.length()>1){
			cout << '.' << s.substr(1,s.length()-1);
		}
		cout << "E" << -f;
	}else{
		s.erase(s.begin()+delim);
		g = s.find_last_not_of('0',s.length());
		s = s.substr(0,g+1);
		cout << s[0];
		if(s.length()>1){
			cout << '.' << s.substr(1,s.length()-1);
		}
		if(delim > 1){
			cout << "E" << delim-1;
		}
	}
}
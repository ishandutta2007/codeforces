#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
	string s;
	cin >> s;
	int del = s.find('e');
	int k = s.find('.');
	string t = s.substr(del+1,s.length()-del-1);
	int h = atoi(t.c_str());
	s = s.substr(0,del);
	if(s[k+1]=='0' && s.length()==k+2){
		s.erase(s.begin()+k+1);
	}
	if(h==0){
		if(k==s.length()-1){
			s.erase(s.begin()+k);
		}
		cout << s;
	}else{
		s.erase(s.begin()+k);
		if(h>0){
			int u = s.find_last_not_of('0',s.length());
			s = s.substr(0,u+1);
			while(h+k>s.length()){
				s += '0';
			}
			k += h;
			cout << s.substr(0,k);
			if(s.length()>k){
				cout << "." << s.substr(k,s.length()-k);
			}
		}else{
			int u = s.find_last_not_of('0',s.length());
			s = s.substr(0,u+1);
			while(k+h<1){
				s = '0' + s;
				k++;
			}
			k+=h;
			cout << s.substr(0,k);
			if(s.length()>k){
				cout << "." << s.substr(k,s.length()-k);
			}
		}
	}
}
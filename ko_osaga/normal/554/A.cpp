#include <cstdio>
#include <string>
#include <iostream>
#include <set>
using namespace std;
set<string> s;

string t;
int main(){
	cin >> t;
	for(int i=0; i<=t.size(); i++){
		for(char j = 'a'; j <= 'z'; j++){
			s.insert(t.substr(0,i) + j + t.substr(i,t.size()));
		}
	}
	cout << s.size();
}
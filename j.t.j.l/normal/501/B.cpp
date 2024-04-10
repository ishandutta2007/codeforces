#include<bits/stdc++.h>

using namespace std;

map<string, string> s;

string s1, s2;

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>s1>>s2;
		int flag = 0;
		for(auto j = s.begin(); j != s.end(); j++)
			if (j -> second == s1){
				j -> second = s2;
				flag = 1;
				break;
			}
		if (!flag)
			s[s1] = s2;
	}
	cout<<s.size()<<endl;
	for(auto j = s.begin(); j != s.end(); j++)
		cout<<(j -> first) <<' '<< (j->second)<<endl;
	return 0;
}
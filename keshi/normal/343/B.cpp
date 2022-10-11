#include <bits\stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	vector <char> a;
	a.push_back(s[0]);
	for (int i=1; i<s.size(); i++){
		if (a.back()==s[i]){
			a.pop_back();
		}
		else{
			a.push_back(s[i]);
		}
	}
	if (a.size()>0){
		cout << "NO";
	}
	else{
		cout << "YES";
	}
	
	return 0;                                                                                                                              
}
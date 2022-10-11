#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	int o=0;
	for (int i=0; i<s.size(); i++){
		if (s[i]>='A' && s[i]<='Z'){
			o+=2;
			s[i]+=32;
		}
		o-=1;
	}
	if (o>0){
		for (int i=0; i<s.size(); i++){
			s[i]-=32;
		}
	}
	cout << s;
	return 0;
}
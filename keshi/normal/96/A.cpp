#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	char l=s[0];
	int n=1,i;
	for (i=1; i<s.size(); i++){
		if (s[i]==l){
			n+=1;
		}
		else{
			l=s[i];
			n=1;
		}
		if (n>=7){
			cout << "YES";
			break;
		}
	}
	if (i==s.size()){
		cout << "NO";
	}
	return 0;
}
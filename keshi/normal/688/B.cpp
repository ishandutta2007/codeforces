#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	cout << s;
	for (int i=s.size()-1; i>-1; i--){
		cout << s[i];
	}
}
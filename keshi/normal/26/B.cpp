#include <bits/stdc++.h>
using namespace std;
long long ans, k;
string s;
int main(){
	cin >> s;
	k = 0;
	for (int i=0; i<s.size(); i++){
		if (s[i] == '('){
			k++;
		}
		else if (k > 0){
			k--;
		}
		else{
			ans++;
		}
	}
	cout << s.size() - (ans + k);
	return 0;
}
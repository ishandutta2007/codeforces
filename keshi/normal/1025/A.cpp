#include <bits/stdc++.h>
using namespace std;
map <string,bool> m;
int main(){
	int n,a[26]={0};
	string s;
	cin >> n >> s;
	if (n>1 && n<=26){
		for (int i=0 ;i<n; i++){
			a[s[i]-'a']++;
		}
		int f=0;
		for (int i=0; i<26; i++){
			if (a[i]==1){
				f++;
			}
		}
		if (f==n){
			cout << "No";
			return 0;
		}
		cout << "Yes";
		return 0;
	}
	cout << "Yes";
	return 0;
}
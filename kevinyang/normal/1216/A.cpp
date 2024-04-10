#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int count = 0;
	for(int i = 0; i<n; i+=2){
		if(s[i]==s[i+1]){
			count++;
		}
	}
	cout << count << "\n";
	for(int i = 0; i<n; i+=2){
		if(s[i]==s[i+1]){
			count++;
			cout << "ab";
		}
		else{
			cout << s[i] << s[i+1];
		}
	}
	cout << "\n";
	return 0;
}
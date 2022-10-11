#include <bits/stdc++.h>
using namespace std;
bool check(string a,string d){
	if (a==d){
		return 0;
	}
	for (int i=0; i<a.size()/2; i++){
		if (a[i]!=a[a.size()-i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	string s,s1,s2,s3;
	cin >> s;
	int n=s.size();
	for (int i=1; i<n-1; i++){
		if (check(s.substr(i,n)+s.substr(0,i),s)){
			cout << 1;
			return 0;
		}
	}
	for (int i=0; i<n/2; i++){
		if (s[i]!=s[0]){
			cout << 2;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}
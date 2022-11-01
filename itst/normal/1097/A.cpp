#include<bits/stdc++.h>
//This code is written by Itst
#define ll long long
using namespace std;

int main(){
	string a , s[5];
	cin >> a;
	for(int i = 0 ; i < 5 ; ++i)
		cin >> s[i];
	for(int i = 0 ; i < 5 ; ++i){
		if(a[0] == s[i][0] || a[1] == s[i][1]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
//https://codeforces.com/problemset/problem/1672/A
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=n;
		while(n--){
			int a;cin>>a;
			ans^=a;
		}
		if(ans&1)puts("errorgorn");else puts("maomao90");
	}
	return 0;
}
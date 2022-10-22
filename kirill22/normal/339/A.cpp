#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	bool flag =true;
	ll n,m,k,h,ans=0;
	string s,s1;
	cin >>s ;
	int a[3]={0};
	for(int i=0;i<s.size();i+=2){
		a[s[i]-'1']++;
	}
	for(int i=0;i<a[0];i++){
		if (flag){
			cout << "1";
			flag=false;
		}
		else cout << "+1";
	}
	for(int i=0;i<a[1];i++){
		if (flag){
			cout << "2";
			flag=false;
		}
		else cout << "+2";
	}
	for(int i=0;i<a[2];i++){
		if (flag){
			cout << "3";
			flag=false;
		}
		else cout << "+3";
	}
	
	return 0;
}
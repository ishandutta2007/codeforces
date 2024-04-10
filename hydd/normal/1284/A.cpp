#include<iostream>
#include<string>
using namespace std;
int n,m,T,x;
string s[51],t[51];
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>s[i];
	for (int i=0;i<m;i++) cin>>t[i];
	cin>>T;
	while (T--){
		cin>>x; x--;
		cout<<s[x%n]<<t[x%m]<<endl;
	}
	return 0;
}
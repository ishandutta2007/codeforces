#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;s="s"+s;
		if((s[1]=='Y'||s[1]=='y')&&(s[2]=='E'||s[2]=='e')&&(s[3]=='S'||s[3]=='s'))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
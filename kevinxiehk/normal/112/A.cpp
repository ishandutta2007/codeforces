#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.length();i++){
		if(a[i]<='Z')a[i]+=('a'-'A');
		if(b[i]<='Z')b[i]+=('a'-'A');
		if(a[i]>b[i]){
			cout<<"1"<<endl;
			return 0;
		}
		else if(b[i]>a[i]){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	cout<<"0"<<endl;
	return 0;
}
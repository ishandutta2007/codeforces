#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int s=a+b+c+d;
		if(s){
			if(s==4)s=2;else s=1;
		}
		cout<<s<<endl;
	}
	return 0;
}
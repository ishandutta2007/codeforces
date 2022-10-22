#include<iostream>
using namespace std;
int main(){
	int n,t=0,t1=1,l=0;string s;cin>>n>>s;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){t1++;l=0;}
		if(s[i]==s[i-1] && l==0){t++;l=1;}
		if(i>=2 && s[i]==s[i-1] && s[i]==s[i-2]) t+=10129;
	}
	//cout<<t1<<" "<<t<<endl;
	cout<<min(n,min(t,2)+t1);
}
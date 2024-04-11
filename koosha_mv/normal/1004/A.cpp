#include<iostream>
using namespace std;
int main(){
	int x,ans=2,gh,n,d;cin>>n>>d;
	if(n==1){cout<<2;return 0;}
	cin>>gh;
	for(int i=1;i<n;i++){
		cin>>x;
		ans++;
		if((x-d)-gh>d)
			ans++;
		if((x-d)-gh<d)
			ans--;
		gh=x;
	}
	cout<<ans;
}
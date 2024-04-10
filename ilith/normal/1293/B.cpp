#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=(double)1.000000/i;
	}
	cout<<ans;
	return 0;
}
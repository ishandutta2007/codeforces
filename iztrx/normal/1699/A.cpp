#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,x;
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>x;
		if(x&1)cout<<"-1\n";
		else cout<<"0 0 "<<x/2<<"\n";
	}
}
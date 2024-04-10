#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,m;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		cout<<m*(m-1)/2+m*(n*(n+1)/2)<<"\n";
	} 
}
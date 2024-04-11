#include<iostream>
using namespace std;
int deg[100009],deg2[100009];
int main(){
	int y,x,n;cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		deg2[deg[x]]--,deg2[deg[x]+1]++,deg2[deg[y]]--,deg2[deg[y]+1]++,deg[x]++,deg[y]++;
	}
	if((deg2[2]))
		cout<<"NO";
	else cout<<"YES";
}
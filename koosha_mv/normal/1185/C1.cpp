#include<iostream>
#include<algorithm>
using namespace std; 
int main(){
	int n,m,i,j;
	cin>>n>>m;
	int t[n];
	for(i=0;i<n;i++){
		cin>>t[i];
		int total=t[i];
		sort(t,t+i);
		for(j=0;j<i;j++){
			if(total +t[j]>m)
			break;
			total+=t[j];
		}
		cout<<i-j<<" ";
	}
}
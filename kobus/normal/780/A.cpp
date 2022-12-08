#include<bits/stdc++.h>
using namespace std;
int v[112345];
int main(){
	int n;
	cin>>n;
	int m=0,resp=0;
	for(int i=0;i<2*n;i++){
		int y;
		cin>>y;
		if(v[y]==0){
			v[y]=1;
			m++;
		}
		else{
			m--;
		}
		if(m>resp){
			resp=m;
		}
	
	}
	cout<<resp<<"\n";
	return 0;
}
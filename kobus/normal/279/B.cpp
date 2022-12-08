#include<bits/stdc++.h>
using namespace std;
int v[112345];

int main(){

	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	
	}
	int tg=0,resp=0,respar=0;
	for(int i=0;i<n;i++){
		tg+=v[i];
		while(tg>t){
			tg-=v[i-respar];
			respar--;
		}
		respar++;
		if(respar>resp){
			resp=respar;
		}
	}
	cout<<resp<<"\n";
	return 0;
}
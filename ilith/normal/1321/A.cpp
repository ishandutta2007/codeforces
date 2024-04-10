#include<bits/stdc++.h>
using namespace std;
int n;
int a[1001];
int b[1001];
int u,v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(a[i]>b[i]){
			u++;
		}
		if(a[i]<b[i]){
			v++;
		}
	}
	if(!u){
		cout<<-1;
		return 0;
	}
	else cout<<v/u+1;
	return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int v[1123];

int main(){
	
	int n,m,k,dismin=100,resp;
	cin>>n>>m>>k;
	m=m-1;
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	for (int i=0;i<n;i++){
		if (v[i]<=k && v[i]!=0){
			int dis= abs(m-i);
			if (dis<dismin){
				dismin=dis;
				resp=10*abs(m-i);
			}
		}
	}

	cout<<resp<<"\n";
	return 0;
}
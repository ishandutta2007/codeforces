#include<bits/stdc++.h>
using namespace std;
int t,n,u;
int a[1010];
int mex(){
	int i,j;
	for(i=0;a[i]>=2;i++){}
	for(j=0;a[i+j]>=1;j++){}
	return i*2+j;
}
int main(){
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		cin>>n;
		while(n--){
			cin>>u;
			a[u]++;
		}
		cout<<mex()<<'\n';
	}
	return 0;
}
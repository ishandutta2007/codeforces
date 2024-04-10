#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f;
void out(int x){cout<<x,exit(0);}
int main(){
	cin>>m>>n;
	if(n==1)out(-1);
	if(n==2&&m==3)out(11);
	if(n==3&&m==5)out(11);
	for(;;){
		if(n>=m+m)out(ans+1);
		if(n>=m)out(ans+(n==m?5:3));
		if(!f)m-=n-2,ans=4,f=1;
		else{
			if(n/2==1)out(-1);
			m-=n/2-1,ans+=2;
		}
	}
	return 0;
}
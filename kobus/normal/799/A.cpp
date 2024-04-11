#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	int c1=0,n1=n;
	while(n1>0){
		if(c1%t==0){
			n1-=k;
		}
		c1++;
	}
	int tempo=0,t1,t2=d;
	while(n>0){
		if(tempo%t==0){
			n-=k;
		}
		if((tempo-d)%t==0 && tempo>=d){
			n-=k;
		}
		tempo++;
	}
	//cout<<c1<<" "<<tempo<<"\n";
	if(tempo<c1){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	return 0;
}
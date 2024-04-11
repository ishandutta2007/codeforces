#include<iostream>
using namespace std;
int main(){
	long long t,q,a,b,n,s;
	cin>>q;
	for(long long i=0;i<q;i++){
		cin>>a>>b>>n>>s;
		t=min((s/n),a);
		s-=t*n;
		if(s<=b)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
#include<iostream>
using namespace std;
int main(){
	int aa,bb,n,q,x,a,b;string s;cin>>q;
	for(int i=0;i<q;i++){
		cin>>n>>x>>a>>b;
		aa=max(a,b);
		bb=min(a,b);
		a=min(aa+x,n);
		x-=(min(aa+x,n)-aa);
		b=max(1,bb-x);
		cout<<a-b<<endl;
	}
	
}
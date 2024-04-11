#include<iostream>
using namespace std;
int main(){
	long long q,a,b,c;cin>>q;
	for(int pq=0;pq<q;pq++){
		cin>>a>>b>>c;
		if(b*2<=c)
			cout<<a*b<<endl;
		else{
			cout<<((a/2)*c)+(a%2)*b<<endl;
		}
	}
	
}
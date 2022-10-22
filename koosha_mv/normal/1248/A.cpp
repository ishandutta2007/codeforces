#include<iostream>
using namespace std;
int main(){
	long long q,n,tf,tz,f,z,x;
	cin>>q;
	for(long long i=0;i<q;i++){
		cin>>n;
		tf=0;tz=0;f=0;z=0;
		for(long long i=0;i<n;i++){
			cin>>x;
			if(x%2==0)
				tz++;
			else
				tf++;
		}
		cin>>n;
		for(long long i=0;i<n;i++){
			cin>>x;
			if(x%2==0)
				z++;
			else
				f++;
		}
		cout<<f*tf+z*tz<<endl;
	}
	
}
#include<iostream>
using namespace std;
int f(long long x){
	if((x*3/2)>x+1)
		return 1;
	return 0;
}
int main(){
	long long t,x,y;cin>>t;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		if(x==y)
			cout<<"YES";
		else{
		x=x-(x%2);
		if(f(x)==1)
			cout<<"YES";
		else{
			if(x*3/2>=y)
				cout<<"YES";
			else
				cout<<"NO";
		}
	}
		cout<<endl;
	}
	
}
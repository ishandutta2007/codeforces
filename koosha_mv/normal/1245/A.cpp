#include<iostream>
using namespace std;
int gcd(int a, int b) 
{  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
        return a; 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
int main(){
	int q,n,m;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n>>m;
		if(gcd(n,m)==1)
			cout<<"Finite"<<endl;
		else
			cout<<"Infinite"<<endl;
	}
}
#include <iostream>
#include <algorithm>
using namespace std;
 
int  n,m,k,s,ss,x,y;

int main(){
     for (int i=0; i<3; i++)
	{     
		cin>>n;
		s+=n;
	}
     for (int i=0; i<3; i++)
	{     
		cin>>m;
		ss+=m;
	}
	cin>>k;
	if (s%5!=0) x=(s/5)+1; else x=s/5;
	if (ss%10!=0) x+=(ss/10)+1; else x+=ss/10;
	if (x<=k ) cout<<"YES"; else cout<<"NO";
	
     return 0;
}
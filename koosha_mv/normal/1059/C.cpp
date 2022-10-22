#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t=1;
	cin>>n;
	while(n){
		if(n==3){
			printf("%d %d %d",t,t,3*t);
			return 0;}
		for(int i=1;i<=n;i+=2){
			printf("%d ",t);
		}
		n/=2;
		t*=2;
	}
	return 0;
}
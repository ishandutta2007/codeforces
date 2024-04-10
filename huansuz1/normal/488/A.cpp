#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

long long n,i,p,x=1;

int main(){
	cin>>n;
	for (int i=1; i<123456; i++)   {
		p=abs(n+i);
		while(p!=0){
		   	if (p%10==8) {cout<<i; return 0;}
		    p/=10;
		}                       
	}

		                                                  

	return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

long long a,b,c,n,res,p1,p2;


int main(){
	cin>>n>>a>>b>>c;
	                                     
	p1 = n / a;
	if (n % a > b)
		p1 += 1 + (n%a-b)/(b-c);

    res = p1;

    p2 =1+(n-b)/(b-c);                        

	if (n >= b)        
		res = max(res, 1+(n-b)/(b-c) + (n-p2*(b-c))/a);

	cout<<res;
	 
    return 0;
}
// Hydro submission #6253c09c48f7830132791a48@1649655964442
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    for(;;)
    {
        if(n) n-=__gcd(a,n);
        else
        {
			printf("1\n");
			return 0;
		}
        if(n) n-=__gcd(b,n);
        else
        {
        	printf("0\n");
        	return 0;
		}
    }
    return 0;
}
// Hydro submission #62550c3217cd4d0a41764c68@1649740851879
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,b,a,t=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        string s;
        cin>>s>>b>>a;
        if(b>=2400&&a>b)
        {
        	printf("YES\n");
        	return 0;
		}
    }
	printf("NO\n");
    return 0;
}
// Hydro submission #6253cd79ca53060146716ace@1649659257861
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s=0;
    string c;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>c;
    	if(c[1]=='+') s++;
		if(c[1]=='-') s--;	
    }
    printf("%d\n",s);
    return 0;
}
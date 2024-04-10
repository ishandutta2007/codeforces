// Hydro submission #62591c6f37de167dd82bc47c@1650007152024
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k=0,s,d,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>s>>d;
    	do k++;
    	while((k-s)%d||k<s);
	}	
    printf("%d\n",k);
    return 0;
}
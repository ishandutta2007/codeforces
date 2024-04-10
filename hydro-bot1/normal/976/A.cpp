// Hydro submission #6259214f37de167dd82bd318@1650008409367
#include<bits/stdc++.h>
using namespace std;
bool f;
int main()
{
    int i,n,t=0;char s;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>s;
    	if(s-48) f=true;
    	else t++;
	}
    if(f)
    {
        printf("1");
       	for(i=0;i<t;i++)
       	printf("0");
       	cout<<endl;
   	}
    else printf("0");
    return 0;
}
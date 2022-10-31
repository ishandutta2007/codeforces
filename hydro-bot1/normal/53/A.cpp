// Hydro submission #6247f9da0bc575b66aa58742@1648884187479
#include<bits/stdc++.h>
using namespace std;
char c[1000],s[1000],mns[1000];
int n;
int main()
{
    cin>>c>>n;
    while(n--)
	{
    	cin>>s;  
    	if(!strncmp(c,s,strlen(c)))
		{
    		if(!mns[0]) strcpy(mns,s);     
    		if(strcmp(s,mns)<0) strcpy(mns,s);   
		}
	}
	if(mns[0]) printf("%s",mns);    
	else printf("%s",c);   
    return 0;
}
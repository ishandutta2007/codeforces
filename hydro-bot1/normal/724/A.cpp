// Hydro submission #62550d32ac286d0a56b86b33@1649741159498
#include<bits/stdc++.h>
using namespace std;
int d(string x)
{
    if(x=="sunday") return 0;
    if(x=="monday") return 1;
    if(x=="tuesday") return 2;
    if(x=="wednesday") return 3;
    if(x=="thursday") return 4;
    if(x=="friday") return 5;
    if(x=="saturday") return 6;
}
int main()
{
    string x,y;
    cin>>x>>y;
    int a=d(x),b=d(y),s;
    while(a>b) a-=7;
	s=(b-a)%7;
	if(!s||s==2||s==3)
	printf("YES\n");
	else printf("NO\n"); 
    return 0;
}
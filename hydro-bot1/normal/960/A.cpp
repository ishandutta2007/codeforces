// Hydro submission #625920e2cc64917dc466542e@1650008313164
#include<bits/stdc++.h>
#define no printf("NO\n"),exit(0); 
using namespace std;
int r,s,t;
int main()
{
    char c;
    while(cin>>c)
    {
    	if(c==97&&(s||t)) no; 
        if(c==97) r++;
		if(c==98&&t) no;
        if(c==98) s++;
        if(s&&!r) no;
        if(c==99) t++;
    }
    if((r==t||s==t)&&s)
    printf("YES\n");
    else printf("NO\n");
    return 0;
}
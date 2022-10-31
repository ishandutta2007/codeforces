// Hydro submission #625921c7cc64917dc46655ae@1650008520474
#include<bits/stdc++.h>
using namespace std;
bool f;
int main()
{
    int i,n,t=0,s=0,mn=100;
    char c;cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;
        if(c==120) t++;
        else 
        {
            if(t>2)
			f=true;
            t=0;
        }
        if(t<3) s++;
    }
	if(t>2) f=true;
    if(f) printf("%d\n",n-s);
    else printf("0\n");
    return 0;
}
// Hydro submission #62550675ac286d0a56b85cc6@1649739382352
#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin>>a;b=a;
    int p=b.find("AB");
    if(p+1)
    {
        b.replace(p,2,".");
        p=b.find("BA");
        if(p+1)
		{
			printf("YES\n");
			return 0;
		}
    }
    b=a,p=b.find("BA");
    if(p+1)
    {
        b.replace(p,2,".");
        p=b.find("AB");
        if(p+1)
		{
			printf("YES\n");
			return 0;
		}
    }
    printf("NO\n");
    return 0;
}
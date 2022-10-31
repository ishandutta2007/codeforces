// Hydro submission #6274cc1d997df5291339cfb1@1651821598451
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i;
	string s;
    cin>>t;
    bool a,b,c,d,e,f,g,h;
    for(i=0;i<t;i++)
	{
        cin>>n>>s;
        a=s[0]==50;b=s[1]==48;
        c=s[2]==50;d=s[3]==48;
        e=s[n-4]==50;f=s[n-3]==48;
        g=s[n-2]==50;h=s[n-1]==48;
        printf(a&&b&&c&&d||a&&b&&c&&h||a&&b&&g&&h||a&&f&&g&&h||e&&f&&g&&h?"YES\n":"NO\n"); 
    }
    return 0;
}
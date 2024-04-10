#include <iostream>

using namespace std;
int n,k,g;bool r,t;char s[100];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){cin>>s[i];
    if(s[i]=='T'&&!r)t=true;if(s[i]=='G'){if(!t)r=true;g=i;}}
    if(r)
    for(int i=g;i<n;i+=k){if(s[i]=='#') break;if(s[i]=='T')return cout<<"YES",0;}
    else
     for(int i=g;i>=0;i-=k){if(s[i]=='#') break;if(s[i]=='T')return cout<<"YES",0;}
    cout<<"NO";
    return 0;
}
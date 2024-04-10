#include <iostream>

using namespace std;
int n,sa,fa;string s;
int main()
{
    cin>>n>>s;
    for(int i=1;i<n;i++){if(s[i-1]=='F'&&s[i]=='S')fa++;if(s[i-1]=='S'&&s[i]=='F')sa++;}
    if(sa>fa)cout<<"YES";
    else cout<<"NO";

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
int ans[100006];
int main()
{
    char s[100006];
cin>>s;
int n=strlen(s);
for(int i=1;i<n;i++)
{
    if(s[i]==s[i-1])
        ans[i]=ans[i-1]+1;
    else ans[i]=ans[i-1];
}
cin>>n;
int a, b;
for(int i=1;i<=n;i++)
{
    cin>>a>>b;
    cout<<ans[b-1]-ans[a-1]<<'\n';
}
return 0;
}
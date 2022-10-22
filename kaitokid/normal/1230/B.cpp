#include <iostream>

using namespace std;

int main()
{
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    if(k==0){cout<<s;return 0;}
if(n==1){cout<<0;return 0;}
    if(s[0]!='1'&&k>0){s[0]='1';k--;}
    for(int i=1;i<n;i++)
    {
        if(s[i]!='0'&&k>0){s[i]='0';k--;}
    }
    cout<<s;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%4==0)cout<<"YES";
    else if(n%7==0)cout<<"YES";
    else if(n%44==0)cout<<"YES";
    else if(n%47==0)cout<<"YES";
    else if(n%74==0)cout<<"YES";
    else if(n%77==0)cout<<"YES";
    else if(n%444==0)cout<<"YES";
    else if(n%447==0)cout<<"YES";
    else if(n%474==0)cout<<"YES";
    else if(n%477==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}
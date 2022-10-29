#include <iostream>

using namespace std;

int main()
{
    int n,a[1000],i,c=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(i=0;i<n;++i)
    {
        if(a[i]==0) c++;
    }
    if(n==1 && c==1) cout<<"NO";
    else if(n==1 && c==0) cout<<"YES";
    else if(c==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
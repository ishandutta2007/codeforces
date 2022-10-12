#include <iostream>
#include <string>

using namespace std;

int main()
{  
    string a;
    cin>>a;
    int n=a.size();
    int open=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]=='H')
            ans++;
        if(a[i]=='9')
            ans++;
        if(a[i]=='Q')
            ans++;

    }

    if(ans>0)
    cout<<"YES";
    if(ans==0)
    cout<<"NO";
}
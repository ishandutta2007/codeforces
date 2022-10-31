// Hydro submission #6274d17ebda16328ffbafef6@1651822975558
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string c="blue",l="unlock",s;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(s=="lock"||s=="unlock") l=s;
        else if(l=="unlock") c=s;
    }
    cout<<c<<endl;
    return 0;
}
// Hydro submission #62590d87cc64917dc466454f@1650003336539
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
    if(a[i]<b[i])
    {
        printf("-1\n");
        return 0;
    }
    cout<<b<<endl;
    return 0;
}
// Hydro submission #625ceb6581ef68d42bcbabc4@1650256741700
#include<bits/stdc++.h>
using namespace std;
string c,s;
int main()
{
    cin>>s;
    int t=0,l=s.size(),i;
    for(i=0;i<l;i++)
    {
        c+=s[(l+1)/2+t-1];
        t=i%2?-t:-t+1;
    }
    cout<<c<<endl;
    return 0;
}
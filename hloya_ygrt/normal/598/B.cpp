#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int n,k,l,r;
   // cin>>n;
    string s,mod;
    cin>>s;
    mod=s;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>l>>r>>k;
        l--;
        r--;
        k=k%(r-l+1);
        for (int i=l;i<=r;i++)
        {
            if (i-k>=l)
            {
                mod[i]=s[i-k];
                continue;
            }
            if (i==l)
            {
                mod[i]=s[r-k+1];
                continue;
            }
            int len1=i-l+1;
            mod[i]=s[r-k+len1];
        }
        s=mod;
    }
    cout<<s<<endl;
    return 0;
}
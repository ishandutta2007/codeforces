#include<bits/stdc++.h>
using namespace std;
long long x[10101];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        bool ok=true;
        for(int i=0;i<n;i++)
            if(x[i]<i)
                ok=false;
            else    x[i+1]+=x[i]-i;
        if(ok)
            puts("YES");
        else    puts("NO");
    }
    return 0;
}
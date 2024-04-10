#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main()
{
    long n,i,x,c=0,ans=0;
    map < long ,long > a;
    cin>>n;
    for(i=0;i<2*n;++i)
    {
        cin>>x;
        if(a[x]>0) {a[x]--;c--;}
        else {a[x]++;c++;}
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;
}
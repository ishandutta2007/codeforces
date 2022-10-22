#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,z=0,x,i,maxi=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        z+=x;
        maxi=max(maxi,x);
    }
    cout<<max(maxi,(long long)(ceil((z*1.0)/(n-1))));
    return 0;
}
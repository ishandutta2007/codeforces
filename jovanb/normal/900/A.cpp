#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,b1=0,b2=0,x,y,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x>>y;
        if(x<0)b2++;
        else b1++;
    }
    if(b1<2 || b2<2)cout<<"Yes";
    else cout<<"No";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,x,br,h,i;
    cin>>n>>h;
    br=n;
    for(i=0;i<n;i++){
        cin>>x;
        if(x>h)br++;
    }
    cout<<br;
    return 0;
}
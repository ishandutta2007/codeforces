#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,k,br=0,xold,x,i;
    cin>>n>>k;
    cin>>xold;
    br=1;
    for(i=1;i<n;i++){
        cin>>x;
        if(x-xold>k)br=0;
        br++;
        xold=x;
    }
    cout<<br;
    return 0;
}
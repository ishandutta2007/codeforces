#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long x,k,a,b,c;
    cin>>a>>b>>c;
    a*=10;
    for(k=1;k<=b+10;k++){
        x=a/b;
        a%=b;
        if(x==c){cout<<k;return 0;}
        a*=10;
    }
    cout<<-1;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long long br=0,a,b,c,n,x,i;
    cin>>a>>b>>c>>n;
    for(i=0;i<n;i++){
        cin>>x;
        if(x>b && x<c)br++;
    }
    cout<<br;
    return 0;
}
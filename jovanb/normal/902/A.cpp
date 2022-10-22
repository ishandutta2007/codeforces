#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n,m,a,trena,aold,x,i;
    cin>>n>>m;
    cin>>a>>trena;
    if(a!=0){cout<<"NO";return 0;}
    aold=a;
    for(i=1;i<n;i++){
        cin>>a>>x;
        trena-=a-aold;
        if(trena<0){cout<<"NO";return 0;}
        trena=max(trena,x-a);
        aold=a;
    }
    trena-=m-aold;
    if(trena<0)cout<<"NO";
    else cout<<"YES";
    return 0;
}
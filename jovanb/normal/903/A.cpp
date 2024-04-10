#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,x,i,j,k,b=0;
    cin>>n;
    for(i=0;i<n;i++){
        b=0;
        cin>>x;
    for(j=0;j<50;j++){
        for(k=0;k<50;k++){
            if(7*j+3*k==x && b==0){cout<<"YES\n";b=1;}
        }
    }
    if(b==0)cout<<"NO\n";
    }
    return 0;
}
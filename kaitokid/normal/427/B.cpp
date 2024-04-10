#include <bits/stdc++.h>

using namespace std;

int main()
{ios::sync_with_stdio(0);
    int n,t,c,l=0,x,ans=0;

    cin>>n>>t>>c;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x<=t){l++;}else{l=0;}
        if(l>=c){ans++;}

    }
    cout<<ans;
    return 0;
}
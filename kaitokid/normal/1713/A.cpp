#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int mxx=0,mxy=0,mnx=0,mny=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==0){mxy=max(mxy,y);mny=min(mny,y);}
        if(y==0){mxx=max(mxx,x);mnx=min(mnx,x);}

    }
          cout<<2*(mxx-mnx+mxy-mny)<<endl;

    }

    return 0;
}
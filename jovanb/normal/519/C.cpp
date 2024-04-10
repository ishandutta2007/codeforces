#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long br=0,n,m;
    cin>>n>>m;
    while(n+m>=3 && n>=1 && m>=1){
        if(n>=m){n-=2;m-=1;}
        else{m-=2;n-=1;}
        br++;
    }
    cout<<br;
    return 0;
}
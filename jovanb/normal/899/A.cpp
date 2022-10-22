#include <bits/stdc++.h>

using namespace std;
long br[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,x=0,i,a;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        br[a]++;
    }
    if(br[2]<=br[1]){
    x+=br[2];
    br[1]-=br[2];
    x+=br[1]/3;
    cout<<x;
    }
    else cout<<br[1];
    return 0;
}
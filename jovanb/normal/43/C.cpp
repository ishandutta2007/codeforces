#include <bits/stdc++.h>
using namespace std;
int br[3];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i,x;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        br[x%3]++;
    }
    cout<<min(br[1],br[2])+br[0]/2;
    return 0;
}
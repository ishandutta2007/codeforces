#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,i=1;
    cin>>n;
    while(i<n){
        cout<<i<<" "<<n<<" ";
        n--;
        i++;
    }
    if(i==n)cout<<i;
    return 0;
}
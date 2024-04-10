#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int k,d,i;
    cin>>k>>d;
    if(d==0){
        if(k>1)cout<<"No solution";
        else cout<<0;
        return 0;
    }
    cout<<d;
    for(i=1;i<k;i++)cout<<0;
    return 0;
}
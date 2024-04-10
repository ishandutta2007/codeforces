#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int a,b,c,v;
    cin>>a>>b>>c;
    cout<<max(a,max(b,c))-min(a,min(b,c));

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int b,g,n;
    cin>>b>>g>>n;
    b=min(b,n);
    g=min(g,n);
    cout<<b+g-n+1<<endl;
    return 0;
}
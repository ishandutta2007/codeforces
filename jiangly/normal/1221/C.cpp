#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int c,m,x;
        cin>>c>>m>>x;
        cout<<min(c,min(m,(c+m+x)/3))<<endl;
    }
    return 0;
}
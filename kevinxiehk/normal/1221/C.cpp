#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int x=min(a,b);
    c+=(max(a,b)-min(a,b));
    if(x>c){
        int z=x-c;
        if(z%3==2)z++;
        z/=3;
        x-=z;
        c+=2*z;
    }
    cout<<min(x,c)<<endl;
    return;
}
int main(){
    int q;
    cin>>q;
    while(q--)solve();
    return 0;
}
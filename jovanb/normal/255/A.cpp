#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n,a=0,b=0,c=0,x,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        if(i%3==1)a+=x;
        else if(i%3==2)b+=x;
        else c+=x;
    }
    if(a>b && a>c)cout<<"chest";
    else if(b>a && b>c)cout<<"biceps";
    else cout<<"back";
    return 0;
}
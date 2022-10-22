#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n,m,i;
    cin>>n>>m;
    if(m<n-1){cout<<-1;return 0;}
    if(m>2*(n+1)){cout<<-1;return 0;}
    m-=n-1;
    if(m<=n-1){
        for(i=0;i<n-1;i++){
            if(m>0){cout<<"011";m--;}
            else cout<<"01";
        }
        cout<<"0";
        return 0;
    }
    else{
        for (i=0;i<2 && m>0;i++){
           cout<<"1";
           m--;
        }
        for(i=0;i<n-1;i++){
            if(m>0){cout<<"011";m--;}
            else cout<<"01";
        }
        cout<<"0";
        while(m>0){
            cout<<"1";
            m--;
        }
        return 0;
    }
    return 0;
}
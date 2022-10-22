#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long long br=0,x,n;
    cin>>n;
    if(n==0){
        cout<<"O-|-OOOO";
        return 0;
    }
    while(n>0){
        x=n%10;
        n/=10;
        br=0;
        if(x>4){
            cout<<"-O|";
            x-=5;
        }
        else cout<<"O-|";
        while(x>0){
            x--;
            cout<<"O";
            br++;
        }
        cout<<"-";
        for(int i=0;i<4-br;i++)cout<<"O";
        cout<<endl;
    }
    return 0;
}
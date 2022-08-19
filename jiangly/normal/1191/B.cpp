// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]){
        if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]){
            cout<<0<<endl;
        }else if(a[0][0]+1==a[1][0]&&a[1][0]+1==a[2][0]){
            cout<<0<<endl;
        }else if(a[0][0]==a[1][0]||a[1][0]==a[2][0]){
            cout<<1<<endl;
        }else if(a[0][0]+1==a[1][0]||a[1][0]+1==a[2][0]||a[0][0]+2==a[1][0]||a[1][0]+2==a[2][0]){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
    }else if(a[0][1]!=a[1][1]&&a[1][1]!=a[2][1]&&a[2][1]!=a[0][1]){
        cout<<2<<endl;
    }else{
        if(a[0][1]==a[2][1]){
            swap(a[1],a[2]);
        }
        if(a[1][1]==a[2][1]){
            swap(a[0],a[2]);
        }
        sort(a,a+2);
        if(a[0][0]==a[1][0]||a[0][0]+1==a[1][0]||a[0][0]+2==a[1][0]){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
    }
    return 0;
}
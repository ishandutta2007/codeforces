#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=1009;
int n;
int main(){
    cin>>n;
    if(n<=10){
        for(int i=1;i<=n/2;++i){
            cout<<1<<" "<<i<<endl;
            cout<<2<<" "<<i<<endl;
        }
        if(n&1){
            cout<<"0 0"<<endl;
        }
    }
    else{
        cout<<"-1 0"<<endl;
        cout<<"1 0"<<endl;
        cout<<"-2 1"<<endl;
        cout<<"0 1"<<endl;
        cout<<"2 1"<<endl;
        n-=5;
        for(int i=2;;++i){
            if(n){
                cout<<-i-1<<" "<<i<<endl;
                n--;
            }
            if(n){
                cout<<-i+1<<" "<<i<<endl;
                n--;
            }
            if(n){
                cout<<i-1<<" "<<i<<endl;
                n--;
            }
            if(n){
                cout<<i+1<<" "<<i<<endl;
                n--;
            }
            if(!n)break;
        }
    }
    return 0;
}
/*
1
2
codeforces
technocup

*/
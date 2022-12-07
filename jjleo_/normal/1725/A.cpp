#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;


int main(){
    ll n,m;
    cin>>n>>m;
    if(m==1){
        cout<<n-1<<endl;
    }else if(n==1){
        cout<<m-1<<endl;
    }else{
        cout<<(m-1)*n<<endl;
    }
}
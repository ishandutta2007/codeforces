//Problem B
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n,k;

int main(){
    cin>>n>>k;
    if(k<=n+1)cout<<((k-1)>>1);
    else if(k<(n<<1))cout<<(((n<<1)-k+1)>>1);
    else cout<<"0";
    return 0;
}
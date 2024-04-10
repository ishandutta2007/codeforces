#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    int n,a,p,b;cin>>n;int l[n];
    for(int i=0;i<n;i++){cin>>p;l[i]=p%2;}
    if((l[0]!=l[1] && l[0]!=l[2])){cout<<1<<endl;return 0;}
    for(int i=1;i<n-1;i++){
        if((l[i] !=l[(i-1)] && l[i] !=l[(i+1)])){cout<<i+1<<endl;return 0;}
        }
    cout<<n<<endl;
    }
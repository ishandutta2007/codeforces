#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n<=9){cout<<n<<endl;return 0;}
    int t=9;
    int num1=9;
    while(num1*10+9<n){t+=9;num1*=10;num1+=9;}
    n-=num1;
    while(n>0){
        t+=n%10;
        n/=10;
    }
    cout<<t<<endl;
    return 0;
}
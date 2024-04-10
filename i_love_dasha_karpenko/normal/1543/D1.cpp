#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
//#define endl '\n'
const int DIM = 2E5+7;
int xo(int a,int b,int k){
    int ret = 0,mult = 1;
    while(a>0 || b>0){
        int n1 = a%k,n2 = b%k;
        ret+=(n1+n2)%k*mult;
        a/=k;
        b/=k;
        mult*=k;
    }
    return ret;
}
int rev(int a,int k){
    int ret = 0,mult = 1;
    while(a>0){
        int n1 = a%k;
        ret+=(k-n1)%k*mult;
        a/=k;
        mult*=k;
    }
    return ret;
}
int sign = 1,add = 0;
int F(int a,int k){
    if (sign==-1)
        a = rev(a,k);
    return xo(a,add,k);
}
int solve(){
    int n,k;
    cin>>n>>k;
    sign = 1;
    add = 0;
    for(int i = 0;i<n;++i){
        int val = F(i,k);
        cout<<val<<endl;
        int ret;
        cin>>ret;
        if (ret==1)
            return 1;
        add = rev(add,k);
        add = xo(add,val,k);
        sign = -sign;
    }
    return 1;
}
int main() {

   // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
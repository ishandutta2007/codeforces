#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
ll a[mn];
int rem[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    ll b=0,w=0;
    for(int i=0;i<n;i++){
        if(i&1){
            b+=a[i]/2;
            w+=a[i]-a[i]/2;
        }
        else{
            w+=a[i]/2;
            b+=a[i]-a[i]/2;
        }
    }
    printf("%lld",min(b,w));
}
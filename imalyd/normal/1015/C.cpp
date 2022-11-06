#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uhoh(i) {printf("%d",i);return 0;}
int n;
ll m,d[100005],t;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        t+=a,d[i]=a-b;
    }
    m=t-m,sort(d+1,d+n+1);
    if(m<=0)uhoh(0)
    for(int i=n;i;i--){
        m-=d[i];
        if(m<=0)uhoh(n-i+1)
    }
    uhoh(-1)
    return 0;
}
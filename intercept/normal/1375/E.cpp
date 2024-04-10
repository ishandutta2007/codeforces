#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1009;
int n;
int a[M],c[M];
vector<pii>ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i=1;i<=n;++i){
        vector<int>p;
        for(int j=i+1;j<=n;++j){
            if(a[i]>a[j]){
                p.eb(j);
            }
        }
        sort(p.begin(),p.end(),[&](const int&l,const int &r){
            return a[l]==a[r]?l>r:a[l]>a[r];
        });
        for(auto o:p)ans.eb(i,o);
    }
    for(auto o:ans){
        swap(a[o.fi],a[o.se]);
    }
    for(int i=2;i<=n;++i){
        if(a[i-1]>a[i]){
            puts("-1");
            return 0;
        }
    }
    cout<<ans.size()<<endl;
    for(auto o:ans){
        cout<<o.fi<<" "<<o.se<<endl;
    }
    return 0;
}
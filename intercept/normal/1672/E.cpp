#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
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
const int M=2e5+9;
int n;
int a[M],b[M],c[M];

int main(){
    cin>>n;
    int l=n,r=5000000;
    while(l<r){
    	int mid=l+r>>1;
    	cout<<"? "<<mid<<endl;
    	int x;
    	cin>>x;
    	if(x==1)r=mid;
    	else l=mid+1;
    }
    int ans=l;
    for(int i=2;i<=n;++i){
    	cout<<"? "<<l/i<<endl;
    	int x;
    	cin>>x;
    	if(x)ans=min(ans,x*(l/i));
    }
    cout<<"! "<<ans<<endl;
    return 0;
}
/*
6
2
1 2
3
1 1 2
4
1 2 1 2
5
1 1 1 2 2
6
1 1 2 2 2 2
*/
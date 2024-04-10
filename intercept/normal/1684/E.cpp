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
const int M=2e5+9;
int n,k;
int a[M],c[M],w[M];
int t[M<<1];
void push(int x,int y){
    for(t[x+=n-1]=y;x;x>>=1)t[x>>1]=a[t[x]]>a[t[x^1]]?t[x]:t[x^1];
}
map<int,int>b;
void work(){
    b.clear();
    cin>>n>>k;
    int r=k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        w[i]=a[i];
        b[a[i]]++;
        push(i,i);
    }
    for(int i=0;i<n&&k;++i){
        if(b[i]==0){
            int x=t[1];
            if(a[x]<i)break;
            b[a[x]]--;
            push(x,0);
            a[x]=i;
            b[i]++;
            k--;
        }
    }
    int d=0,m=0;
    for(int i=0;i<=n;++i){
        if(b[i]==0){
            m=i;
            break;
        }
    }
    b.clear();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(a[i]<m){
            if(i==1||a[i]!=a[i-1])d++;
        }
    }
    for(int i=1;i<=n;++i)a[i]=w[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(a[i]>=m){
            if(i==1||a[i]!=a[i-1])d++;
            b[a[i]]++;
        }
    }
    int p=0;
    for(auto o:b){
        c[++p]=o.se;
    }
    sort(c+1,c+p+1);
    for(int i=1;i<=p;++i){
        int x=c[i];
        while(r>k&&x){
            r--;
            x--;
        }
        if(x==0)d--;
    }
    cout<<d-m<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}

/*
2
6 1
0 1 2 5 6 6
1
6 2
1 2 8 0 0 0
1
4 2
4 4 6 6
*/
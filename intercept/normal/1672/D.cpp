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
void work(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],c[i]=0;
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int l=1,r=1,la=0;r<=n;){
        if(l<=n&&a[l]==b[r]){
            la=a[l];
            l++;
            r++;
        }
        else {
            if(c[b[r]]&&la==b[r]){
                c[b[r]]--;
                r++;
            }
            else{ 
                if(l<=n){
                    c[a[l]]++;
                    l++;
                }
                else {
                    puts("NO");
                    return;
                }
            }
        }
    }
    puts("YES");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
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
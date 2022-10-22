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
int n;
string s;
void work(){
    cin>>s;
    n=s.length();
    int top=0,o=0;
    for(int i=0;i<n;++i){
        if(s[i]=='A')top++;
        if(s[i]=='B')top--;
        if(top<0){
            puts("NO");
            return;
        }
    }
    puts(s[n-1]=='A'?"NO":"YES");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
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
int ca=0;
void work(){
    ca++;
    int n=5,m;
    cin>>n>>m;
    
    char s[10][10];
    int p=100;
    int x=n,y=m,flag=0;
    for(int i=1;i<=n;++i){
        
        for(int j=0;j<m;++j){
            char ch;
            cin>>ch;
            s[i][j]=ch;
            if(s[i][j]=='R'){
                if(p!=100&&j<p){
                    flag=1;
                }
                else p=min(p,j);
            }
        }
    }
    puts(!flag?"YES":"NO");
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*\
1
3 3
EEE
EER
REE
*/
#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,ll y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}

const int M=1e6+9;
int q;
char s[M];
int ca=0;
void work(){
    ca++;

    int a,b;
    scanf("%d%d%s",&a,&b,s+1);
    int n=strlen(s+1),ans=0,p=0,flag=0;
    for(int i=1,la=0;i<=n;++i){
        if(s[i]=='.'&&(i+1>n||s[i+1]=='X')){
            int l=i-la;
            if(l>=b&&l<a){
                puts("NO");
                return;
            }
            if(l>b*4-2+a){
                puts("NO");
                return;
            }
            if(l>=b*2){
                flag++;
                p=l;
            }
            else if(l>=a)ans^=1;
        }
        if(s[i]=='X')la=i;
    }

    if(flag>1){
        puts("NO");
        return;
    }
    if(flag==0){
        puts(ans?"YES":"NO");
        return;
    }
    if(ans==0){
        if(p>=a*3||a+b*2-2>=p)puts("YES");
        else puts("NO");
        return;
    }
    else {
        if(p-a-(2*b-1)>=b||p<a*2)puts("NO");
        else puts("YES");
    }
}
int main(){
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        work();
        
    }
    return 0;
}
/*
1
5 4
...............X.....
*/
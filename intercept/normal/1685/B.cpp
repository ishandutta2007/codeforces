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
int a,b,c,d;
char s[M];
void work(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    scanf("%s",s+1);
    int l=0,r=0;
    n=strlen(s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='A')l++;
        if(s[i]=='B')r++;
    }
    if(l!=a+c+d||r!=b+c+d){
        puts("NO");
        return;
    }
    a=b=0;
    for(int i=2;i<=n;++i){
        if(s[i]=='B'&&s[i-1]=='A')a++;
        if(s[i]=='A'&&s[i-1]=='B')b++;
    }
    int t=0;
    priority_queue<int>x,y;
    for(int i=1,l=0;i<=n;++i){ 
        if(s[i]!=s[i-1])l++;
        if(s[i+1]==s[i]||i==n){
            if(l%2==0){
                if(s[i]=='B'){
                    c-=l/2;
                    x.push(l/2);
                }
                else {
                    d-=l/2;
                    y.push(l/2);
                }
            }
            else t+=l/2;
            l=1;
        }
    }
    if(c<0){
        while(!x.empty()){
            int l=x.top();
            x.pop();
            if(abs(c)>=l){
                c+=l;
                d-=(l-1);
            }
            else{
                d+=c+1;
                c=0;
            }
            if(c==0)break;
        }
    }
    else if(d<0){
        while(!y.empty()){
            int l=y.top();
            y.pop();
            if(abs(d)>=l){
                d+=l;
                c-=(l-1);
            }
            else{
                c+=d+1;
                d=0;
            }
            if(d==0)break;
        }
    }
    c=max(c,0);
    d=max(d,0);
    puts((c+d-t<=0)?"YES":"NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*

1
10 12 34 1
AABABBBABAABABABABABABABABABABAABBBABABAAABABABABAABABABABAAAAAABABABABABABABBBBBBBBBBABABAB
1
1 1 2 3
ABABABBAABAB

ABABABAB
(l-2)/2
l/21
ABAB A BA B
ABABABABA
ABAB A BABA
BABABABAB
BABA B ABAB
(l-1)/2

*/
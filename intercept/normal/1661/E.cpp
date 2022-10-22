#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=5e5+9;
int n,q;
char c[3][M];
vector<pii>p[M];
int bit[M],ans[M],s[M],la[M];
void add(int x,int v){
    for(;x<=n;x+=x&-x)bit[x]+=v;
}
int ask(int x,int rex=0){
    for(;x;x-=x&-x)rex+=bit[x];
    return rex;
}
int get(int i,int rex=0){
    for(int j=0;j<3;++j)rex|=(c[j][i]&1)<<j;
    return rex;
}
int calc(int x){
    if(!x)return 0;
    if(x==5)return 2;
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<3;++i)scanf("%s",c[i]+1);
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        p[l].eb(r,i);
    }
    for(int i=n;i>=1;--i){
        s[i]=get(i);
        add(i,calc(s[i]));
        add(i+1,-calc(s[i]));
        if((s[i]&s[i+1])==0)add(i+1,calc(s[i]));
        else{
            if(s[i]==5){
                if(s[i+1]==5){
                    la[i]=la[i+1];
                }
                else {
                    la[i]=i;
                    if((s[i]&s[i+1])!=s[i])add(i+1,1);
                }
            }
            else {
                if(s[i]==7){
                    if(s[i+1]==5){
                        int y=la[i+1];
                        if(s[y+1]==7){
                            add(i+1,-1);
                            add(y+1,1);
                        }
                        else{
                            add(i+1,-1);
                        }
                    }
                }
            }
        }
        for(auto o:p[i]){
            ans[o.se]=ask(o.fi);
        }
    }
    for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
    return 0;
}
/*
12
100101011101
110110010110
010001011101
1
1 12
*/
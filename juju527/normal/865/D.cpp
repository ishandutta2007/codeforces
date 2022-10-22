#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long
priority_queue<int,vector<int>,greater<int> >q;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n;
    ll ans=0;
    n=read();
    for(int i=1;i<=n;i++){
        int x;
        x=read();
        if(!q.empty()&&x-q.top()>0){
            ans+=x-q.top();
            q.pop();
            q.push(x);
        }
        q.push(x);
    }
    printf("%lld\n",ans);
    return 0;
}
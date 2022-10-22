#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll z=0;
priority_queue<int>q;
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++){
        int x;
        x=read();
        q.push(x);q.push(x);
        if(q.top()>x)z=q.top()+z-x;
        q.pop();
    }
    printf("%lld\n",z);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 131072
int n;
int gcd(int a,int b){
    while(b)a%=b,a^=b^=a^=b;
    return a;
}
pair<int,int> merge(pair<int,int> a,pair<int,int> b){
    pair<int,int> c;
    c.first=gcd(a.first,b.first);
    if(a.first==c.first)c.second+=a.second;
    if(b.first==c.first)c.second+=b.second;
    return c;
}
pair<int,int> seg[1<<18];
int q(int a,int b){
    pair<int,int> c;
    a+=n-1,b+=n-1;
    while(b>a){
        if(a&1)c=merge(c,seg[a]),a++;
        if(!(b&1))c=merge(c,seg[b]),b--;
        a>>=1,b>>=1;
    }
    if(a==b)c=merge(c,seg[a]);
    return c.second;
}
int main(){
    int i,x,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&x),seg[n+i].first=x,seg[n+i].second=1;
    for(i=n-1;i;i--)seg[i]=merge(seg[i*2],seg[i*2+1]);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%d\n",b-a+1-q(a,b));
    }
}
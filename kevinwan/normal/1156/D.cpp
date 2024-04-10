#include <bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
int p[mn],q[mn],s[mn],t[mn];
int f(int x){return p[x]==x?x:(p[x]=f(p[x]));}
int g(int x){return q[x]==x?x:(q[x]=g(q[x]));}
void m1(int a,int b){
    a=f(a);
    b=f(b);
    if(s[a]<s[b])p[a]=b,s[b]+=s[a];
    else p[b]=a,s[a]+=s[b];
}
void m2(int a,int b){
    a=g(a);
    b=g(b);
    if(t[a]<t[b])q[a]=b,t[b]+=t[a];
    else q[b]=a,t[a]+=t[b];
}
bool u[mn],v[mn];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)p[i]=q[i]=i,s[i]=t[i]=1;
    int a,b,c;
    for(i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(!c)m1(a,b);
        else m2(a,b);
    }
    long long ans=0;
    for(i=1;i<=n;i++){
        ans+=1LL*(s[f(i)]-1)*(t[g(i)]-1);
        if(!u[f(i)])u[f(i)]=1,ans+=1LL*s[f(i)]*(s[f(i)]-1);
        if(!v[g(i)])v[g(i)]=1,ans+=1LL*t[g(i)]*(t[g(i)]-1);
    }
    cout<<ans;
}
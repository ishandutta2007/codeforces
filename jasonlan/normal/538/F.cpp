#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200010;
int n;
int a[maxn],ord[maxn],ans[maxn];
int tr[maxn];
void add(int p){
    while(p<=n)++tr[p],p+=p&-p;
}
int query(int p){
    int res=0;
    while(p)res+=tr[p],p^=p&-p;
    return res;
}
bool cmp(int x,int y){
    if(a[x]^a[y])return a[x]<a[y];
    return x<y;
}
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int main(){
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read(),ord[i]=i;
    sort(ord+1,ord+1+n,cmp);
    for(int i=1,p;i<=n;++i){
        p=ord[i];
        for(int j=1,l,r;j<n;++j){
            l=j*(p-1)+2;r=min(j*p+1,n);
            if(l>n)break;
            ans[j]+=query(r)-query(l-1);
        }
        add(p);
    }
    for(int i=1;i<n;++i)
        cout<<ans[i]<<' ';
    return 0;
}
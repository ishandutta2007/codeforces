// Hydro submission #620d97ea2b27c6d6c13c10b1@1645058026484
// Problem: CF1254C Point Ordering
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1254C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Code by _Arahc_
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=2003;
inline int read(){
    int x=0;bool w=0;char c=getchar();
    while(c<'0' || c>'9') w|=c=='-',c=getchar();
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10^48);
}
inline int ask(int op,int i,int j,int k){
    int res;
    cout<<op<<" "<<i<<" "<<j<<" "<<k<<"\n";
    cout.flush();
    cin>>res;
    return res;
}

int n,pos,a[max_n];
int S,mxs=-1,s[max_n];

int ans[max_n];

inline bool cmp(int i,int j){
    if(a[i]!=a[j])
        return a[i]<a[j];
    if(a[i]==1)
        return s[i]>s[j];
    return s[i]<s[j];
}

signed main(){
//  freopen(".in","r",stdin),
//  freopen(".out","w",stdout);
    n=read(),pos=2;
    for(register int i=1;i<=n;++i)
        ans[i]=i;
    for(register int i=3;i<=n;++i)
        if(ask(2,1,pos,i)==1)
            pos=i;
    for(register int i=2;i<=n;++i)
        if(i!=pos){
            s[i]=ask(1,1,pos,i);
            if(s[i]>S){
                mxs=i,
                S=s[i];
            }
        }
    pos=mxs;
    for(register int i=2;i<=n;++i)
        if(i!=pos)
            a[i]=ask(2,1,pos,i);
    sort(ans+2,ans+1+n,cmp);
    cout<<"0 ";
    for(register int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}
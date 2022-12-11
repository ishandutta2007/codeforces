#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int N=2e5+10;
const int mod=0;
const ull base=131;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
template<typename T> bool chkmax(T &a,T b) { return a<b?a=b,1:0; };
template<typename T> bool chkmin(T &a,T b) { return a>b?a=b,1:0; };
int add(int a,int b) { return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b) { return a-b<0?a-b+mod:a-b; }
void inc(int &a,int b) { a=(a+b>=mod?a+b-mod:a+b); }
void dec(int &a,int b) { a=(a-b<0?a-b+mod:a-b); }
int n,m,a[N],s[N],st[N],top=0;
ull hsh[N],hsh2[N],pw[N];
ull gethsh(int l,int r) {
    return hsh[r]-hsh[l-1]*pw[r-l+1];
}
ull gethsh2(int l,int r) {
    return hsh2[r]-hsh2[l-1]*pw[r-l+1];
}
bool check(int l,int r) {
    if(l==r) return 1;
    int t=(r-l+1)/2;
    return gethsh(l,l+t-1)==gethsh2(n-r,n-(r-t+1));
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("CF1045B.in","r",stdin);
    freopen("CF1045B.out","w",stdout);
#endif
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=gi();
    for(int i=1;i<n;i++) s[i]=a[i+1]-a[i],hsh[i]=hsh[i-1]*base+s[i];
    reverse(s+1,s+n);
    for(int i=1;i<n;i++) hsh2[i]=hsh2[i-1]*base+s[i];
    pw[0]=1;for(int i=1;i<n;i++) pw[i]=pw[i-1]*base;
    for(int i=1;i<=n;i++) {
        bool flag=1;
        if(i!=1) flag&=check(1,i-1);
        if(i!=n) {
            flag&=(a[1]+a[i]+m==a[i+1]+a[n]);
            if(i!=n-1) flag&=check(i+1,n-1);
        }
        if(flag) st[++top]=(a[1]+a[i])%m;
    }
    sort(st+1,st+top+1);
    printf("%d\n",top);
    for(int i=1;i<=top;i++) printf("%d ",st[i]);
    return 0;
}
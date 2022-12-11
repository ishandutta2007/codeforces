#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int mod=0;
const int N=1e6+10;
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
char s[N];
int n,a[N];
ll ans=0;
map<int,int> cnt;
int main() {
#ifndef ONLINE_JUDGE
    freopen("CF1045I.in","r",stdin);
    freopen("CF1045I.out","w",stdout);
#endif
    cin>>n;
    for(int i=1;i<=n;i++) {
        scanf("%s",s+1);int len=strlen(s+1);
        for(int j=1;j<=len;j++) a[i]^=1<<(s[j]-'a');
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++) {
        ans+=cnt[a[i]];
        for(int j=0;j<26;j++) ans+=cnt[a[i]^(1<<j)];
    }
    ans-=n;ans/=2;
    printf("%lld\n",ans);
    return 0;
}
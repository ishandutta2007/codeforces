#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e5+10;
const ll mod=1e9+7;
int p[mn],s[mn],a[mn],ra[mn];
multiset<int>mo;
int n;
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
void u(int a,int b){
    a=f(a),b=f(b);
    if(a==b)return;
    p[a]=b;
    if(a<=n)mo.erase(mo.find(s[a]));
    if(b<=n)mo.erase(mo.find(s[b]));
    s[b]+=s[a];
    if(b<=n)mo.insert(s[b]);
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)p[i]=i,s[i]=1;
        for(int i=1;i<=n;i++)scanf("%d",a+i),ra[a[i]]=i;
        mo.clear();
        for(int i=1;i<=n;i++)mo.insert(1);
        bool fail=0;
        for(int i=1;i<=n;i++){
            if(s[f(ra[i])]!=*(--mo.end())){
                fail=1;
                break;
            }
            u(ra[i],ra[i]+1);
        }
        if(fail)printf("No\n");
        else printf("Yes\n");
    }
}
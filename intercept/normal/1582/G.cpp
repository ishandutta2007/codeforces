#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=1000009;
int n;
ll ans;
int a[M];
char c[M];
bool vis[M];
vector<int>p[M],s[M];
vector<pii>l;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    scanf("%s",c+1);
    for(int i=2;i<M;++i){
        if(!vis[i]){
            s[i].eb(n+1);
            for(int j=i;j<M;j+=i)vis[j]=1;
            for(ll j=i;j<M;j*=i){
                for(int k=j;k<M;k+=j){
                    p[k].eb(i);
                }
            }
        }
    }
    for(int i=n;i>=1;--i){
        if(c[i]=='/'){
            for(auto o:p[a[i]]){
                s[o].eb(i);
                l.eb(o,i);
            }
        }
        else{
            for(auto o:p[a[i]]){
                if(s[o].back()!=n+1)s[o].pop_back();
            }
        }
        while(l.size()&&l.back().se<s[l.back().fi].back())l.pop_back();
        if(l.size())ans+=l.back().se-i;
        else ans+=n-i+1;
    }
    printf("%lld\n",ans);
    return 0;
}
/*


*/
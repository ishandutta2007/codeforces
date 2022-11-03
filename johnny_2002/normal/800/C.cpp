#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=2e5+10;

int mod,h[N];
int f[N],tr[N];
int pos[N];


int findrev(int x,int mod){
    ///gcd(x,y)==1

    int a1=1,b1=0,c1=x;
    int a2=0,b2=1,c2=mod;
    while (c2){
        int tmp=c1/c2;
        a1=a1-tmp*a2;
        b1=b1-tmp*b2;
        c1=c1-tmp*c2;
        swap(a1,a2);
        swap(b1,b2);
        swap(c1,c2);
    }
    return a1;
}
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
int DP(int val){
    if (f[val]!=-1) return f[val];
//    cout<<val<<'\n';
    int ans=0,sum=0;
    for(int i=val;i<mod;i+=val) {
        if (pos[i]==val) sum+=!h[i];
        else if (maximize(ans,DP(pos[i]))) tr[val]=pos[i];
    }
    f[val]=ans+sum;
    return f[val];
}
void solve(){
    for(int i=1;i<mod;i++) pos[i]=__gcd(i,mod);
    memset(f,-1,sizeof(f));
    DP(1);
    vector <int> ans;
    int cur=1;
    while (cur){
        for(int i=cur;i<mod;i+=cur) if (pos[i]==cur&&!h[i]) ans.push_back(i);
        cur=tr[cur];
    }
    int n1=ans.size();
    for(int i=n1-1;i>0;i--){
        int com=pos[ans[i-1]];
        ans[i]=((1LL*findrev(ans[i-1],mod)*(ans[i]/com))%mod+mod)%mod;
    }
    if (!h[0]) ans.push_back(0);
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}
int main(){
    int n;
    cin>>n>>mod;
    while (n--){
        int val;
        cin>>val;
        h[val]=1;
    }
    solve();
}
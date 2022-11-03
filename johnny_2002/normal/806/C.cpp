#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=2e5+10;
const int MOD=1e9+7;

int n;
ll a[N];
int h[60],pos[60],add[60];
map <ll,int> ma;

struct BIT{
    int b[N];
    void add(int x,int val){
        while (x<=n){
            b[x]+=val;
            x+=x&-x;
        }
    }
    int get(int x){
        int ans=0;
        while (x){
            ans+=b[x];
            x-=x&-x;
        }
        return ans;
    }
    int findpos(int val){
        if (!val) return 0;
        int ans=0;
        for(int i=1<<int(log2(n));i>=1;i>>=1){
            int pos=ans+i;
            if (pos>n) continue;
            if (val>b[pos]) val-=b[pos],ans=pos;
        }
        return ans+1;
    }
}mbit;

bool check(int drop){
    add[0]=drop;
    mbit.add(pos[0],drop);
    h[0]-=drop;
    for(int i=1;pos[i]<=n;i++){
        if (h[i]>=h[i-1]){
            add[i]=h[i]-h[i-1];
            h[i]=h[i-1];
            mbit.add(pos[i],add[i]);
        }
    }
    int n1=mbit.get(n);
    if (n1>h[0]) return 0;
    for(int i=50,pos=n1;pos>0;i--) if (h[i]<h[i-1]){
        int idx=mbit.findpos(pos);
        if (a[idx]>=(1LL<<i)) return 0;
        pos-=h[i-1]-h[i];
    }
    return 1;
}
void solve(){
    for(int i=0;i<=50;i++) pos[i]=lower_bound(a+1,a+n+1,1LL<<i)-a;
    for(int i=1;i<=n;i++){
        if (ma.find(a[i])!=ma.end()) h[ma[a[i]]]++;
        else mbit.add(i,1);
    }
    int cans=0;
    for(int drop=h[0];drop>=0;drop--){
        if (check(drop)) {
            cans++;
            cout<<h[0]<<" ";
        }
        for(int i=0;pos[i]<=n;i++) {
            mbit.add(pos[i],-add[i]);
            h[i]+=add[i];
            add[i]=0;
        }
    }
    if (!cans) cout<<"-1";
}
int main(){
    for(int i=0;i<=50;i++) ma[1LL<<i]=i;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve();
}
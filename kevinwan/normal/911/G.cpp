#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e5+10;
const ll mod=1e9+7;
int a[mn];
vector<pii>mvs;
char seg[mn*4][100];
char t[100];
#define mid ((l+r)>>1)
void comp(char a[100],char b[100]){
    for(int i=0;i<100;i++)t[i]=a[b[i]];
    memcpy(b,t,sizeof(t));
}
void down(int x){
    comp(seg[x],seg[x*2]);
    comp(seg[x],seg[x*2+1]);
}
void upd(int x,int l,int r,int a,int b,int c,int d){
    if(l==a&&r==b){
        for(int i=0;i<100;i++)if(seg[x][i]==c)seg[x][i]=d;
    }
    else {
        down(x);
        iota(seg[x],seg[x]+100,0);
        if (b <= mid)upd(x * 2, l, mid, a, b, c, d);
        else if (a > mid)upd(x * 2 + 1, mid + 1, r, a, b, c, d);
        else upd(x * 2, l, mid, a, mid, c, d), upd(x * 2 + 1, mid + 1, r, mid + 1, b, c, d);
    }
}
void prop(int x,int l,int r){
    if(l==r)printf("%d ",seg[x][a[l]]+1);
    else{
        down(x);
        prop(x*2,l,mid),prop(x*2+1,mid+1,r);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]--;
    for(int i=0;i<mn*4;i++)iota(seg[i],seg[i]+100,0);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,a,b;
        scanf("%d%d%d%d",&l,&r,&a,&b),a--,b--;
        upd(1,1,n,l,r,a,b);
    }
    prop(1,1,n);
}
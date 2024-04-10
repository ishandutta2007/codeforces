#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
#define mid ((l+r)>>1)
int a[mn];
int n;
int num[mn];
int mex(){
    for(int i=0;i<=n;i++)num[i]=0;
    for(int i=0;i<n;i++)num[a[i]]=1;
    for(int i=0;i<=n;i++)if(!num[i])return i;
}
int getl(int x){
    for(int i=0;i<n;i++)if(a[i]==x)return i;
}
void perm();
vector<int>v;
void reg(){
    while(1){
        int m=mex();
        if(m==n)break;
        a[m]=m;
        v.push_back(m);
    }
    perm();
}
void perm(){
    for(int i=0;i<n;i++){
        int x=getl(i);
        if(x==i)continue;
        v.push_back(x);
        a[x]=mex();
        v.push_back(i);
        a[i]=mex();
        reg();
        break;
    }
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
        v.clear();
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        reg();
        printf("%d\n",v.size());
        for(int x:v)printf("%d ",x+1);
        printf("\n");
    }
}
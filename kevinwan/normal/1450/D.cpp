#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=3e5+10;
const ll mod=1e9+7;


int a[mn],num[mn];
bool ans[mn];
int hailveshy2(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],ans[i]=0,num[i+1]=0;
    for(int i=0;i<n;i++)num[a[i]]++;
    int l=0,r=n-1,m=0;
    for(int i=0;i<n;i++){
        if(num[m]>1)break;
        if(a[l]==m+1)l++,m++;
        else if(a[r]==m+1)r--,m++;
        else break;
    }
    int con=inf;
    for(int i=l;i<=r;i++)con=min(con,a[i]);
    if(con==m+1)m++;
    for(int i=0;i<m;i++)ans[n-1-i]=1;
    sort(a,a+n);
    ans[0]=1;
    for(int i=0;i<n;i++)if(a[i]!=i+1)ans[0]=0;
    for(int i=0;i<n;i++)printf("%d",ans[i]);
    printf("\n");
    return 0;
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        hailveshy2();
    }
}
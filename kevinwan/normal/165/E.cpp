#include<bits/stdc++.h>
#include<chrono>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;
typedef pair<ld,ld> pld;
mt19937_64 rng(time(0));
const int mn=1<<22;
int ps[mn],a[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    memset(ps,-1,sizeof(ps));
    for(i=0;i<n;i++){
        ps[a[i]]=a[i];
    }
    for(i=1;i<mn;i++){
        for(j=0;j<22;j++){
            if((i>>j)&1)ps[i]=max(ps[i],ps[i-(1<<j)]);
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",ps[mn-1-a[i]]);
    }
}
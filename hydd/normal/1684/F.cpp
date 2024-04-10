#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[210000],b[210000];
int cnt,num[210000];
int L[210000],R[210000];
int l[210000],r[210000];
vector<int> vec[210000];
void work(int *R){
    for (int i=1;i<=n;i++) vec[a[i]].push_back(i);
    for (int i=1;i<=cnt;i++) vec[i].push_back(n+1);
    for (int i=1;i<=n;i++) b[i]=i;
    for (int i=1;i<=m;i++) b[l[i]]=max(b[l[i]],r[i]);
    for (int i=1;i<=n;i++) b[i]=max(b[i-1],b[i]);
    int ll=n+1,rr=0;
    for (int i=1;i<=n;i++){
        if (i>=ll){ R[i]=n+1; continue;}
        int t=*--upper_bound(vec[a[i]].begin(),vec[a[i]].end(),b[i]);
        int v=*upper_bound(vec[a[i]].begin(),vec[a[i]].end(),i);
        if (v<=b[i]) ll=min(ll,v); rr=max(rr,t);
        R[i]=rr;
    }
    for (int i=1;i<=cnt;i++) vec[i].clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>m; cnt=0;
        for (int i=1;i<=n;i++) cin>>a[i],num[++cnt]=a[i];
        sort(num+1,num+cnt+1); cnt=unique(num+1,num+cnt+1)-num-1;
        for (int i=1;i<=n;i++) a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;
        for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
        work(R);
        reverse(a+1,a+n+1);
        for (int i=1;i<=m;i++){
            int x=l[i],y=r[i];
            l[i]=n-y+1; r[i]=n-x+1;
        }
        work(L);
        reverse(L+1,L+n+1);
        for (int i=1;i<=n;i++) L[i]=n-L[i]+1;
        // for (int i=1;i<=n;i++) cerr<<R[i]<<' '; cerr<<'\n';
        // for (int i=1;i<=n;i++) cerr<<L[i]<<' '; cerr<<'\n';
        int ans=n,j=0;
        for (int i=1;i<=n;i++){
            while (j<n&&L[j+1]<i) j++;
            if (j<=n) ans=min(ans,j-i+1);
            while (j<R[i]) j++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
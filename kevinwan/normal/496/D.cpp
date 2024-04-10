#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
int a[mn],b[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j,x;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        if(x==1)a[i]=1;
        else b[i]=1;
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    vector<pii> ans;
    for(i=1;i<=n;i++){
        int aw=0,bw=0,loc=0;
        bool lw=0,fail=0;
        while(loc<n){
            int cur=loc;
            for(j=1<<16;j;j>>=1){
                if(cur+j>n)continue;
                if(max(a[cur+j]-a[loc],b[cur+j]-b[loc])<i)cur+=j;
            }
            cur++;
            if(max(a[cur+j]-a[loc],b[cur+j]-b[loc])<i)fail=1;
            if(a[cur]-a[loc]>b[cur]-b[loc])aw++,lw=0;
            else bw++,lw=1;
            loc=cur;
        }
        if(fail)continue;
        if(aw==bw)continue;
        if(aw>bw&&lw!=0)continue;
        if(bw>aw&&lw!=1)continue;
        ans.push_back({max(aw,bw),i});
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto th:ans){
        printf("%d %d\n",th.first,th.second);
    }
}
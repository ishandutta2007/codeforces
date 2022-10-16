#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
const int N=200000;
int arr[N+5];
int b[N+5];
int add[N+5];
bool vi[N+5];
pair<int,int> bk[N+5];
vector<int>conn[N+5];
vector<int>pre[N+5];
void bfs(int curr){
    vi[curr]=true;
    for(auto x:conn[curr]){
        if(!vi[x]){
            bfs(x);
            bk[curr].fi=max(bk[curr].fi,bk[x].fi+1);
            if(arr[x]>0){
                pre[curr].pb(x);
                arr[curr]+=arr[x];
            }
        }
    }
    return;
}
void ehh(int k){
    vi[k]=true;
    for(auto x:pre[k])ehh(x);
    cout<<k+1<<" ";
    return;
}
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.fi>b.fi;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){cin>>arr[i];}
    for(int i=0;i<n;i++){cin>>b[i];if(b[i]!=-1)b[i]--;}
    for(int i=0;i<n;i++){
        if(b[i]!=-1)conn[b[i]].pb(i);
        vi[i]=false;
        bk[i].se=i;
        bk[i].fi=0;
    }
    for(int i=0;i<n;i++){
        if(b[i]==-1)bfs(i);
    }
    int ans=0;
    for(int i=0;i<n;i++){ans+=arr[i];}
    cout<<ans<<endl;
    for(int i=0;i<n;i++)vi[i]=false;
    sort(bk,bk+n,cmp);
    for(int i=0;i<n;i++){
        if(!vi[bk[i].se])ehh(bk[i].se);
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 112345
#define INF LLONG_MAX/4

int n,c;
int v[MAXN];
int seg[4*MAXN];
int com[4*MAXN];
int fim[4*MAXN];

int prep(int node, int ncom, int nend){
    if(seg[node]!=INF)return seg[node];
    com[node]=ncom;
    fim[node]=nend;
    if(ncom==nend){
        seg[node]=v[ncom];
        return seg[node];
    }
    int nmid=(ncom+nend)/2;
    seg[node]=min(prep(2*node,ncom,nmid),prep(2*node+1,nmid+1,nend));
    return seg[node];
}

void prep(){
    for(int i=0;i<=4*n;i++)seg[i]=INF;
    prep(1,0,n-1);
}

int query(int node, int i, int j){
    if(j<com[node]||i>fim[node])return INF;
    if(i<=com[node]&&j>=fim[node])return seg[node];
    return min(query(2*node,i,j),query(2*node+1,i,j));
}

int query(int i, int j){
    return query(1,i,j);
}

int memo[MAXN];
int sumac[MAXN];

int sum(int i,int j){
    if(i==0)return sumac[j];
    return sumac[j]-sumac[i-1];
}

int pd(int i){
    if(i==n)return 0;
    if(i>n)return INF;
    int &resp=memo[i];
    if(resp==-1){
        resp=min(v[i]+pd(i+1),sum(i,i+c-1)-query(i,i+c-1)+pd(i+c));
    }
    return resp;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>c;

    for(int i=0;i<n;i++)cin>>v[i];
    prep();
    for(int i=0;i<n;i++)memo[i]=-1;
    sumac[0]=v[0];
    for(int i=1;i<n;i++)sumac[i]=sumac[i-1]+v[i];
    cout<<pd(0)<<endl;
    //for(int i=0;i<n;i++)cout<<pd(i)<<" ";
    //cout<<endl;
}
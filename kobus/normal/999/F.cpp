#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int cf[112345];
int pf[512];
int joy[11];
int memo[512][5123];
int n,k;

int pd(int pl, int lft){
    if(pl==n)return 0;
    int &resp=memo[pl][lft];
    if(resp==-1){
        for(int i=0;i<=k;i++){
            if(i>lft)break;
            if(pl==n-1 || pf[pl+1]!=pf[pl])resp=max(resp,joy[i]+pd(pl+1,cf[pf[pl+1]]));
            else resp=max(resp,joy[i]+pd(pl+1,lft-i));
        }
    }
    return resp;
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n>>k;

    for(int i=0;i<n*k;i++){
        int a;cin>>a;
        cf[a]++;
        //cout<<i<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n*k;j++){
            memo[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++)cin>>pf[i];
    for(int i=1;i<=k;i++)cin>>joy[i];
    sort(pf,pf+n);
    cout<<pd(0,cf[pf[0]])<<endl;

 
    return 0;
}
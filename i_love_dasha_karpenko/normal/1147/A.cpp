#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 10E16
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n,k;
arr A,last,first;
ll t=0;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    ll x;
    for (int i = 1;i<=k;i++){
        cin>>x;
        if (A[x]==0)
            first[x]=t;
        A[x]++;
        last[x]=t++;
    }
    ll res = 0;
    for (int i = 1;i<=n;i++){
        if (A[i]==0){
            res++;
            if (i!=1){
                res++;
            }
            if (i!=n){
                res++;
            }
        }
        else{
            if (i!=1){
                if (A[i-1]==0)res++;
                else{
                    if (last[i-1]<=first[i])res++;
                }
            }
            if (i!=n){
                if (A[i+1]==0)res++;
                else if (last[i+1]<=first[i])
                    res++;
            }
        }
    }
    cout<<res<<endl;
}
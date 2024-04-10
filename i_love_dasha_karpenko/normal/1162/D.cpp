#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
char C[DIM];
struct str{
    ll mx,cn,value;
};
ll n,m;
vector<ll> A[DIM],B[DIM];
arr D;

int F(vector<ll> X,vector<ll> Y){
    if (X.size()!=Y.size())return 0;
    ll l = X.size();
    ll flag = 0;
    for (int i = 0;i<l;i++){
        if (X[i]!=Y[i]){
            return 0;
        }
    }
    return 1;

}

int Check(ll x){
    ll i = 1,j = x;
    while(F(B[j],A[i]) && i<=n ){
        j++; i++;
    }
    if (i>=n)return 1;
    return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll x,y;
    for (int i = 1;i<=m;i++){
        cin>>x>>y;
        if (x>y){
            swap(x,y);
        }
        A[x].push_back(y-x);
        A[y].push_back(n+x-y);
    }
    for (int i = 1;i<=n;i++){
        sort(A[i].begin(),A[i].end());
    }
    for (int i = 0;i<n;i++){
        B[i]=A[i+1];
    }
    for (int i = n;i<n*2;i++){
        B[i]=A[i-n+1];
    }
    arr G;
    G[0]=0;
    for (int i = 1;i<n*2;i++){
        ll k = G[i-1];
        while(k>0 && !F(B[i],B[k])){
            k = G[k-1];
        }
        if (F(B[i],B[k])){
            k++;
        }
        G[i]=k;

    }
    ll gcd = n*2-G[n*2-1];
    if(gcd>=n)
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;

}
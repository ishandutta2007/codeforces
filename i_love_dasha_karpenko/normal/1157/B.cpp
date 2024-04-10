#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 1000000000007
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n,N[10],sum = 0;
arr A,D;
ll R[DIM];
int main()
{
    //freopen("input.txt","r",stdin);

    cin>>n;
    ll cof = 1;
    for (int i = 1;i<=n;i++){
        char x; cin>>x;
        A[i]=x-'0';
        cof*=10;
    }
    cof/=10;
    for (int i = 1;i<=9;i++)cin>>N[i];

    ll i=1;
    while(A[i]>=N[A[i]] && i<=n){
        R[i]=A[i];
        cof/=10;

        i++;
    }
    while(N[A[i]]>=A[i] && i<=n){
        R[i]=N[A[i]];
       // cout<<sum<<' '<<A[i]<<' '<<N[A[i]]<<' '<<cof<<endl;
        cof/=10;
        i++;
    }
    while(i<=n){
        R[i] = A[i];
        cof/=10;
        i++;
    }
    for (int i = 1;i<=n;i++)
        cout<<R[i];
}
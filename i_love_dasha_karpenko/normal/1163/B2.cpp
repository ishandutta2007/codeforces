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
ll n,r=0,nr,orn=1,uno=0,all=0;
arr A;
ll C[DIM],G[DIM];
arr V;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ll mx=0,mi=1;
    for (int i = 1;i<=n;i++){
        cin>>A[i];
        C[A[i]]++;
        if (V[A[i]]==0){all++;
            r++;
            V[A[i]]=1;
        }
        if (C[A[i]]==1)uno++;
        if (C[A[i]]==2)uno--;
        if (C[A[i]]>mx){
            mx = C[A[i]];
            nr = orn-1;
            orn = 1;
            r = all-1;
        }
        else if (C[A[i]]==mx){r--;orn++;nr--;}
        else if (C[A[i]]==mx-1)nr++;
        if (nr==all-1 && (orn==1 || uno==1))
            mi = i;
        if (orn==all-1 && uno==1)mi = i;
        if (r==0 && i!=n)
        mi = i+1;
        //cout<<orn<<' '<<r<<' '<<nr<<endl;
    }
    cout<<mi<<endl;
}
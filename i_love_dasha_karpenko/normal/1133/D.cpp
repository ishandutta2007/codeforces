#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E10
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ld arr[DIM];
ll n,base = 0;
arr A,B;
const ld eps = ld(1)/pow(10,6);

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>A[i];
        A[i]*=-1;
    }
    ld x;
    for (int i  =1;i<=n;i++){
        cin>>x;
        if (A[i]==x && A[i]==0){
            base++; A[i]=INF;
            continue;
        }
        if (A[i]==0)A[i]=INF;
        else
            A[i] = x/A[i];

    }
    sort(A+1,A+1+n);
    ll res=0,cres =1;
    for (int i = 1;i<=n;i++){
        if (A[i]==INF){
            cres = 0;
            break;
        }
        if (A[i]==A[i-1] && i!=1)cres++;
        else cres = 1;
        res = max(res,cres);
    }
    cout<<res+base<<endl;
}
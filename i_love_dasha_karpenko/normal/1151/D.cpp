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
char C[DIM];
struct anger{ll w,pos,a,b;};
ll n;
anger A[DIM];

bool mycompare(anger a,anger b){
    return a.w>b.w;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ll x,y;
    for (int i = 1;i<=n;i++){
        cin>>x>>y;
        A[i]={x-y,i,x,y};
    }
    sort(A+1,A+1+n,mycompare);
    ll res = 0;
    for (int i = 1;i<=n;i++){
        res+=A[i].a*(i-1)+A[i].b*(n-i);
    }
    cout<<res<<endl;
}
// a(j-1)+b(n-j)= aj-a+bn-bj = j(a-b)-a+bn

#include <bits/stdc++.h>

using namespace std;
#define DIM 150007
#define INF 10E16
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll A[5];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>A[0]>>A[1]>>A[2]>>A[3];
    sort(A,A+4);


    cout<<A[3]-A[0]<<' '<<A[3]-A[1]<<' '<<A[3]-A[2]<<endl;
}
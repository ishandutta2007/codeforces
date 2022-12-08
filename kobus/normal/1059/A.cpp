#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define d 256
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 2123456
#define INF numeric_limits<ll>::max()
#define MOD 1000000007

pii v[1123456];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int n,l,a;
    cin>>n>>l>>a;

    for(int i=0;i<n;i++)cin>>v[i].f>>v[i].s;
        for(int i=0;i<n;i++)v[i].s+=v[i].f;
    sort(v,v+n);
    int resp=0;
    for(int i=0;i<n-1;i++)resp+=((v[i+1].f-v[i].s)/a);
    if(n>=1)resp+=v[0].f/a;
    resp+=(l-v[n-1].s)/a;
    cout<<resp<<endl;
    return 0;
 
}
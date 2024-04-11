#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 112
#define int long long
#define INF LLONG_MAX/20
#define double long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007

int v[312345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]=-v[i];
        tot-=v[i];
    }
    sort(v,v+n);
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        int k;
        cin>>k;
        cout<<tot+v[k-1]<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 3241618756

pii v[1123];

bool comp(pii a,pii b){
    if(a.f!=b.f)return a.f>b.f;
    return a.s<b.s;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            int a;
            cin>>a;
            v[i].f+=a;
        }
        v[i].s=i+1;
    }
    sort(v,v+n,comp);
    for(int i=0;i<n;i++){
        if(v[i].s==1){
            cout<<i+1<<endl;
            return 0;
        }
    }

    return 0;
}
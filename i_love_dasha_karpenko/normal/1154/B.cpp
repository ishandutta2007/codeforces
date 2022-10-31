
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
ll n;
arr A;
set<ll> S;
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
        S.insert(A[i]);
    }
    if (S.size()>3){
        cout<<-1<<endl;
        return 0;
    }
    ll mi=INF,mx=0,d=0;
    for (auto it = S.begin();it!=S.end();it++){
        //cout<<*it<<endl;
        mi = min(mi,ll(*it));
        mx = max(mx,ll(*it));
    }
    if (S.size()==2){
            ll r = mx-mi;
    if (r%2==0)r/=2;
        cout<<r<<endl;
        return 0;
    }

    else if (S.size()==3){
        for (auto it = S.begin();it!=S.end();it++){
            if (*it!=mx && *it!=mi)d = max(d,ll(*it));
        }
        //cout<<d<<' '<<mx<<' '<<mi<<endl;
        if (mx-d!=d-mi){
            cout<<-1<<endl;
            return 0;
        }
        cout<<mx-d<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
ll gi(char ch){
    return ch-'a';
}
ll A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,T;
    cin>>n>>T;
    vector<ll> V;
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
        if (i<n-1){
            V.push_back(A[i]+1);
            sum+=po(A[i]+1);
            T+=po(A[i]);
        }
    }
    if (n>1)
    T+=po(A[n-1]);
    T-=po(A[n]);

    if (sum==T){
        cout<<"Yes\n";
        return 0;
    }
    ll dif = sum-T;
    sort(V.begin(),V.end());
    while(dif){
        while(!V.empty() && po(V.back())>dif)V.pop_back();
        if (V.empty())break;
        dif-=po(V.back());
        V.pop_back();
    }
    if (dif==0){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    return 0;
}
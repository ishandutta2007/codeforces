#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;

ll A[DIM];
struct node{
    ll i,j,x;
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum = 0;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            sum+=A[i];
        }
        if (sum%n!=0){
            cout<<"-1\n";
            continue;
        }
        sum/=n;
        vector<node> ans;
        ll ptr = 1;
        for(ll i = n;i>1;--i){
            if (A[i]>=i){
                ptr = i;
                break;
            }
        }
        if (ptr!=1 && A[ptr]>=ptr){
            ll x = A[ptr]/ptr;
            ans.push_back({ptr,1,x});
            A[1]+=ptr*x;
            A[ptr]%=ptr;
            ans.push_back({1,ptr,ptr-A[ptr]});
            ans.push_back({ptr,1,1});
            A[1]+=A[ptr];
            A[ptr] = 0;
            for(ll i = ptr-1;i>1;--i){
                if (A[i]%i!=0){
                    ans.push_back({1,i,i-A[i]%i});
                    A[i]+=i-A[i]%i;
                    A[1]-=i-A[i]%i;
                }
                ans.push_back({i,1,A[i]/i});
                A[1]+=A[i];
                A[i] = 0;
            }
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > Q;
        for(ll i = ptr+1;i<=n;++i){
            if (A[i]==0)continue;
            Q.push({i-A[i],i});
        }
        ll flag = 0;
        while(!Q.empty()){
            ll pos = Q.top().second;
            Q.pop();
            if (pos-A[pos]>A[1]){
                flag = 1;
                break;
            }
            ans.push_back({1,pos,pos-A[pos]});
            ans.push_back({pos,1,1});
            A[1]+=A[pos];
            A[pos] = 0;
        }

        if (flag){
            cout<<"-1\n";
            continue;
        }
        for(ll i = 2;i<=n;++i){

            ll need = sum-A[i];
            if (need==0)continue;
            ans.push_back({1,i,need});
        }
        cout<<ans.size()<<endl;
        for(auto to:ans)cout<<to.i<<' '<<to.j<<' '<<to.x<<endl;
    }
    return 0;
}
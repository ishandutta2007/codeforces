//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
//#define endl '\n'
const ll DIM = 1E5+7;
const ll blocksz = 31;
ll simp[DIM],vis[DIM],cnt;
ll ask(ll num,ll ind){
    if (ind==0)cout<<"A ";
    else cout<<"B ";
    cout<<num<<endl;
    ll ret;
    cin>>ret;
    return ret;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vector<ll> nums;
    for(ll i = 2;i<=n;++i){
        if (simp[i]==1)continue;
        nums.push_back(i);
        for(ll j = i*i;j<=n;j+=i)simp[j] = 1;
    }
    memset(vis,0,sizeof(vis));

    ll flag = 0;
    ll gen = n;
    vector<ll> V;
    for(ll i = 0;i<nums.size();i+=blocksz+1){
        ll nxt = min(ll(nums.size())-1ll,i+blocksz);
        for(ll j = i;j<=nxt;++j){
            ll cnt = 1;
            --gen;
            for(ll ptr = nums[j]*nums[j];ptr<=n;ptr+=nums[j]){
                if (vis[ptr]==0){
                    ++cnt;
                    --gen;
                }
                vis[ptr] = 1;
            }
            ll left = ask(nums[j],1);
            if (left!=cnt)V.push_back(nums[j]);
        }
        if (flag)continue;
        ll left = ask(1,0);

        if (gen!=left){
            flag  = 1;
            //if (nxt!=nums.size()-1)n/=0;
            for(ll j = i;j<=nxt;++j){
                ll left = ask(nums[j],0);

                if (left!=0){
                    V.push_back(nums[j]);
                    flag = 2;
                    break;
                }
            }
           // if (flag==1)n/=0;
        }
    }
    //if (flag==0)n/=0;
    ll res = 1;
    for(ll to:V){
        res*=to;
        ll mult = to*to;
        while(mult<=n){
            ll left = ask(mult,0);
            if (left!=0)res*=to;
            else break;
            mult*=to;
        }
    }
    cout<<"C ";
    cout<<res<<endl;



    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe

//#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM],cnt[DIM];
string OR = "OR",XOR = "XOR",AND = "AND";
ll ask(string s,ll a,ll b){
    cout<<s<<' '<<a<<' '<<b<<endl;
    ll ans;
    cin>>ans;
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 2;i<=n;++i){
        A[i] = ask(XOR,1,i);
        cnt[A[i]]++;
    }
    ll flag = -1;
    for(ll i = 0;i<n;++i){
        if (cnt[i]>1){
            flag = i;
            break;
        }
    }
    ll a = 0;
    if (flag!=-1){
        pair<ll,ll> ps;
        for(ll i = 2;i<=n;++i){
            if (A[i]==flag){
                if (ps.first==0)ps.first = i;
                else{
                    ps.second = i;
                    break;
                }
            }
        }
        ll and1 = ask(AND,ps.first,ps.second);
        ll b = A[ps.first];

        ll mult = 1;
        for(ll y = 1;y<=17;++y){
            if (b&1){
                if (!(and1&1))a+=mult;
            }
            else{
                if (and1&1)a+=mult;
            }
            mult*=2;
            b/=2;
            and1/=2;
        }

    }
    else{
        ll ps = 0;
        ll st = 2;
        for(ll i = 3;i<=n;++i){
            if (((n-1)^A[i])==A[st]){
                ps = i;
                break;
            }
        }
        if (ps==0){
            st = 3;
            for(ll i = 2;i<=n;++i){
                if (i==st)continue;
                if (((n-1)^A[i])==A[st]){
                    ps = i;
                    break;
                }
            }
        }
        ll or1 = ask(OR,1,st);
        ll or2 = ask(OR,1,ps);
        ll b = A[st];
        ll c = A[ps];

        ll mult = 1;
        for(ll i = 1;i<=17;++i){
            if (b&1){
                if (or2&1)a+=mult;
            }
            else{
                if (or1&1)a+=mult;
            }
            mult*=2;
            or1/=2;
            or2/=2;
            c/=2;
            b/=2;
        }

    }

    cout<<"! ";
    cout<<a<<' ';
    for(ll i = 2;i<=n;++i){
        cout<<(A[i]^a)<<' ';
    }
    cout<<endl;
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 1500  +7;
const ll INF = 10E10;
ll A[DIM];
map<ll,ll> M;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k; cin>>n>>k;
    forn(i,n){
        ll mult = 1,r = 0;
        forn(j,k){
            char ch; cin>>ch;
            ll p;
            if (ch=='S')p = 3;
            else if (ch=='E')p = 1;
            else p = 2;
            r += p*mult;
            mult*=4;
        }
        A[i] = r;
        M[r]++;
    }
    ll res = 0;
    forn(i,n){
        for(ll j= i+1;j<=n;j++){
            ll m1 = A[i];
            ll m2 = A[j];
            ll mult = 1;
            ll mask = 0;
            while(m1>0 || m2>0){
                if (m1%4==m2%4)mask+=mult*(m1%4);
                else mask+=mult*(6-m1%4-m2%4);
                mult*=4;
                m1/=4;
                m2/=4;
            }
            M[A[i]]--;
            M[A[j]]--;
            res+=M[mask];
            M[A[i]]++;
            M[A[j]]++;
        }
    }
    cout<<res/3 <<endl;
    return 0;
}
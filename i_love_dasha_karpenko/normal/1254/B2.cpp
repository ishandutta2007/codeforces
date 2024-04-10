#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 10E5+7;
const ll INF = 10E18+173;
ll A[DIM],n,da[DIM];
ll sz;
ll F(ll div){
    ll res = 0,p1 = 1,p2 = -1,sum = 0;
    forn(i,n){da[i] = A[i];A[i]%=div;}
    for(;1;){
        if (p1>n)break;
        while(p1<=n && A[p1]==0)p1++;
        if (A[p1]%div==0){p1++;continue;}
        p2 = p1;
        sum = 0;
        sum+=A[p2];
        while(sum<div){
            p2++;
            sum+=A[p2];
        }
        if (p1==p2){
            A[p1+1]+=A[p1]%div;
            res+=A[p1]%div;
            A[p1]%=div;
            p1++;
            continue;
        }
        ll left = sum-div;
        ll s1 = A[p1];
        ll s2 = A[p2]-left;
        ll fin = p2;
        while(p1!=p2){
            if (s1<s2){
                res+=s1;
                A[p1+1]+=s1;
                A[p1]-=s1;
                s1 = A[p1+1];
                p1++;
            }
            else{
                res+=s2;
                A[p2-1]+=s2;
                A[p2]-=s2;
                s2 = A[p2-1];
                p2--;
            }
        }
        p1 = fin;
    }
    forn(i,n)A[i] = da[i];
    return res;
}
int main()
{
    //cout<<INF<<endl;
    //cout<<fixed<<INF<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    forn(i,n){
        cin>>A[i];
        sz += A[i];
    }
    ll sq = sz;
    if (sz==0){
        cout<<0<<endl;
        return 0;
    }
    ll res= INF;
    if (sz>1)
    res = min(res,F(sz));
    for(ll div = 2;div<=sz && div<DIM;div++){
        if (sz%div==0){
            while(sz%div==0)sz/=div;
            res = min(res,F(div));
            //res = min(res,F(sz/div));
        }

    }
    if (sz>1)
    res = min(res,F(sz));
    if (res==INF)cout<<"-1\n";
    else
    cout<<res<<endl;
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3
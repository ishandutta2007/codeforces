#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

#define F first
#define S second
pii A[3];
bool not_between(ll a,ll b, ll c)
{
    if(a<b)
    {
        return (c<=a || c >= b);
    }
    return (c>=a||c<=b);
}
bool chk(int i,int j,int k)
{
    if(A[i].F ==  A[j].F && not_between(A[i].S,A[j].S,A[k].S))
        return 1;
    if(A[i].S ==  A[j].S && not_between(A[i].F,A[j].F,A[k].F))
        return 1;
    return 0;
}
int main()
{
    cin>>A[0].F>>A[0].S>>A[1].F>>A[1].S>>A[2].F>>A[2].S;
    if(A[0].F == A[1].F && A[1].F == A[2].F)
    {
        cout<<1;
        return 0;
    }
    if(A[0].S == A[1].S && A[1].S == A[2].S)
    {
        cout<<1;
        return 0;
    }
    if(chk(0,1,2)|| chk(1,2,0) || chk(2,0,1))
    {
        cout<<2;
        return 0;
    }
    cout<<3;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

#define LSOne(S) (S & (-S))
// B1 and B2 are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
ll B1[1000005], B2[1000005];

// Array size
int N;

// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query(ll* ft, int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(ll* ft, int k, ll v) {
    for (; k <= N; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v)   {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}
int pos[1000005],pos2[1000005];
int main()
{
    int n,q;
    sd(n),sd(q);
    N = n;
    rep(i,1,n/2+1)
    {
        range_update(i,i,2*i-2);
        range_update(i+n/2,i+n/2,2*i-1);
    }
    int pre = 0;
    while(q--)
    {
        int t,x;
        sd(t);
        if(t==1)
        {
            sd(x);
            range_update(1,n,x);
            if((abs(x))&1)
                pre = 1-pre;
        }
        
        else
        {
            if(pre)
            {
                range_update(1,n/2,-1);
                range_update(n/2+1,n,1);
            }
            else
            {
                range_update(1,n/2,1);
                range_update(n/2+1,n,-1);   
            }
            pre = 1-pre;
        }
    }
    for(int i = 1;i<=n/2;i++)
        {
            int ans = 1+ (range_query(i,i)%n + n)%n;
            pos[2*i-1] = ans;
            pos2[pos[2*i-1]] = 2*i-1;
        }
        for(int i = n/2+1;i<=n;i++)
        {
            int ans = 1+ (range_query(i,i)%n + n)%n;
            pos[2*(i-n/2)] = ans;
            pos2[pos[2*(i-n/2)]] = 2*(i-n/2);
        }
    rep(i,1,n+1)
    printf("%d ",pos2[i]);
    printf("\n");

}
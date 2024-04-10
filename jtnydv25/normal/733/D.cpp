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
#define eb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
struct sol{
    int k,d;
    vi ind;
    sol()
    {
        k = d = 0;
    }
};
map<pii, vii > myp;
int main()
{
    int n;
    sd(n);
    int A[3];
    rep(i,1,n+1)
    {
        cin>>A[0]>>A[1]>>A[2];
        sort(A,A+2);
        set<pii > done;
        pii p = mp(A[0],A[1]);
        int j = 0;
        while(done.find(p) == done.end())
        {
            myp[p].eb(mp(-A[(j+2)%3],i));
            done.insert(p);
            j = (j+1)%3;
            p = mp(min(A[j],A[(j+1)%3]),max(A[j],A[(j+1)%3]));
        }
    }
        int k = 0, d = 0,x[2] = {0};
        for(auto it:myp){
            vii vec = it.S;
            sort(all(vec));
            if(vec.size()>=2)
            {
                int sm = -vec[0].F - vec[1].F;
                if(min(it.F.F,min(it.F.S,sm)) > d)
                {
                    k = 2;
                    d = min(it.F.F,min(it.F.S,sm));
                    x[0] = vec[0].S, x[1] = vec[1].S;
                }
            }
            else
            {
                int sm = -vec[0].F;
                if(min(it.F.F,min(it.F.S,sm)) > d)
                {
                    k = 1;
                    d = min(it.F.F,min(it.F.S,sm));
                    x[0] = vec[0].S;
                }   
            }
        }
    pd(k);
        rep(i,0,k)
        printf("%d ", x[i]);
}
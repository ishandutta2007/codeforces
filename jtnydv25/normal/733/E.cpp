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
string s;
int n;
ll ans(int pos, vi& D, vi& U, vll& SD, vll& SU)
{
    /*print(D);
    print(U);
    print(SD);
    print(SU);*/
    int ind1 = upper_bound(D.begin(),D.end(),pos-1) - D.begin();
    int ind2 = upper_bound(U.begin(),U.end(),pos) - U.begin();
    if(!ind2)
        return pos;
    ind2--;
    int rem1 = D.size() - ind1, rem2 = ind2+1;
    // cerr<<ind1<<" "<<ind2<<" "<<pos<<" "<<" "<<(rem1<=rem2)<<" "<<(ind1+ind2-(int)D.size())<<endl;
    if(rem1 <= rem2)
        return 2*(SD.back()-(ind1>0?SD[ind1-1]:0)) - 2*(SU[ind2] - (ind1+ind2-(int)D.size()>=0?SU[ind1+ind2 - (int)D.size()]:0))+n-pos+1;
    return 2*(SD[ind1+ind2] - (ind1>0?SD[ind1-1]:0)) - 2*SU[ind2] + 2*D[ind1+ind2+1] - pos;
}
vi D,U,D1,U1;
vll SD,SD1,SU1,SU;

int main()
{
    ll preD = 0,preD1 = 0,preU = 0,preU1 = 0;
    cin.tie(NULL);
    cin>>n>>s;
    for(int i = 0;i<n;i++){
        if(s[i] == 'U')
            U.eb(i+1),D1.eb(n-i);
        else
            D.eb(i+1),U1.eb(n-i);
    }
    sort(all(D1));
    sort(all(U1));
    for(int i = 0;i<U.size();i++)
        preU+=U[i],SU.eb(preU);
    for(int i = 0;i<D.size();i++)
        preD+=D[i],SD.eb(preD);
    for(int i = 0;i<U1.size();i++)
        preU1+=U1[i],SU1.eb(preU1);
    for(int i = 0;i<D1.size();i++)
        preD1+=D1[i],SD1.eb(preD1);
    rep(i,1,n+1)
    {
        if(s[i-1] == 'U')
            printf("%lld ", (ans(n-i+1,D1,U1,SD1,SU1)));
        else
            printf("%lld ", (ans(i,D,U,SD,SU)));
    }
}
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
bool X[105];
int main()
{
    int t;
    // sd(t);
    t = 1;
    while(t--)
    {
        int n,k;
        sd(n);sd(k);
        string s;
        cin>>s;
        int posg,post;
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'G')
                posg = i;
            if(s[i] == 'T')
                post = i;
        }
        if((abs(posg-post))%k != 0)
        {
            printf("NO");
            return 0;
        }
        int add = (post > posg)?k:-k;
        while(posg != post)
        {
            if(s[posg] == '#')
            {
                printf("NO");
                return 0;
            }
            posg += add;
        }
        printf("YES");
    }
}
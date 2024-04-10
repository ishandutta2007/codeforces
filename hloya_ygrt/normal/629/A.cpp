#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e2+20, base = 1e9+7;

 int a[maxn];
    int b[maxn];
int main()
{
    //files1;
    //files2;
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
        char c;
        cin >>c;
        if (c!='.'){
            a[i]++;
            b[j]++;
        }
    }
    ll ans = 0;
    for (int i=0;i<n;i++){
        if (a[i]!=0)
            ans+=(a[i]*(a[i]-1))/2;
        if (b[i]!=0)
            ans+=(b[i]*(b[i]-1)) / 2;
    }
    cout<<ans<<endl;
    return 0;
}
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
const int maxn = 1e5+5, base = 1e9+7;

    int m[400],f[400];
int main()
{
    //files1;
    //files2;
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        char c;
        int a,b;
        cin >> c>> a>>b;
        if (c == 'F'){
            for (int j=a;j<=b;j++)
                f[j]++;
        }
        if (c == 'M'){
            for (int j=a;j<=b;j++)
                m[j]++;
        }
    }
    int ans = 0;
    for (int i=1;i<=366;i++){
        ans = max(ans,min(m[i],f[i])*2);
    }
    cout<<ans;
    return 0;
}
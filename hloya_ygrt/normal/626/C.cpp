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
const int maxn = 1e5+500, base = 1e9+7;

int main()
{   int n, m;

    scanf("%d %d",&n,&m);
    int ans = 2;
    while (n||m)
    {
        if (ans%2 == 0&&ans%3!=0&&n){
            n--;
            ans++;
        } else
        {
            if (ans%3==0&&ans%2!=0&&m){
                m--;
                ans++;
            } else
            {
                if (ans%2==0&&ans%3==0&&2*n>3*m&&n){
                    n--;
                    ans++;
                } else
                    if (ans%2==0&&ans%3==0&&2*n<=3*m&&m){
                        m--;
                        ans++;
                        continue;
                    } else
                    ans++;
            }
        }

    }
    ans--;
    cout<<ans;
	return 0;
}
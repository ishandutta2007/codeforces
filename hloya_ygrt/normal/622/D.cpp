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
const int maxn = 1e6+5, base = 1e9+7;

    int ans[maxn]={0};
int main()
{
    int n;
    scanf("%d",&n);
    int m = 2*n;
    for (int i=1,j=1;max(i,j)<=n;i++,j+=2)
        ans[i] = ans[i+n-j] = j;
    for (int i=n+1,j=2;i<=m&&j<n;j+=2,i++)
        ans[i] = ans[i+n-j] = j;

    for (int i=1;i<=m;i++){
        if (ans[i] == 0)
            printf("%d ",n);
        else
            printf("%d ",ans[i]);
    }
	return 0;
}
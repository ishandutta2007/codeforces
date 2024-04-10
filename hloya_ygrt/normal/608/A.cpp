#include <bits\stdc++.h>

const int maxn=2e5;
const int inf=2e9;
const int eps=1e-9;
const int mod=1e9+7;

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define ll long long
#define ld long double

#define forn() for(int i=0;i<n;i++)
#define nfor() for(int i=n-1;i>=0;i--)

using namespace std;

int a[maxn];

int main()
{
    int n,s;
    scanf("%d %d",&n,&s);

    int maxr=-1;

    for (int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        maxr=max(maxr,x+y);
    }

    cout<<max(maxr,s);
    return 0;
}
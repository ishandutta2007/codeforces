#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 5e3+500, base = 1e9+7,maxm= 1e4+5;

int r[maxn],c[maxn];
int tr[maxn],tc[maxn];
int main()
{
    int n,m,k;
    for (int i=0;i<maxn;i++)
        tr[i] = tc[i] = -1;
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<k;i++){
        int t,j,cl;
        scanf("%d %d %d",&t,&j,&cl);
        j--;
        if (t == 1)
        {
            r[j] = cl;
            tr[j] = i;
        } else
        {
            c[j] = cl;
            tc[j] = i;
        }
    }

    for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){

        if (tr[i] > tc[j])
            cout<<r[i]<<' ';
        else
            cout<<c[j]<<' ';
    }
        puts("");
    }
    return 0;
}
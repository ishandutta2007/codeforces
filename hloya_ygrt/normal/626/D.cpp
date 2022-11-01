#include <bits/stdc++.h>

#define f first
#define s second
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define lll unsigned long long


using namespace std;

const int maxn = 1e4+100;
const int maxm = 5000;

int a[maxn];

lll b1[maxn]={0ULL},b2[maxn]={0ULL},s[maxn]={ 0ULL };

void _try(int n)
{
    sort(a,a+n);
    for (int j=1;j<n;j++)
        for (int i=0;i<j;i++){
                if (a[j] >= a[i])
                    b1[a[j]-a[i]]++;
        }
}

int main()
{
    int n;

    scanf("%d",&n);
    for (int i=0;i<n;i++ )
        scanf("%d",&a[i]);
    _try(n);
    for (int i=maxn-2;i>=0;i--){
                s[i]=b1[i]+s[i+1];
        }
    lll cnt1=s[0]*s[0]*s[0],ans= 0;
    for (int j=0;j<=maxm;j++)
        for (int i=0;i<=maxm;i++){
                if (b1[j]!=0&&b1[i]!=0)
                    b2[i+j]+=b1[j]*b1[i];
            }

    for (int i=0;i<=maxm;i++)
        ans+=b2[i]*s[i+1];
    cout<<fixed<<setprecision(20)<<(ld)ans/cnt1;
    return 0;
}
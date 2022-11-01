#include <bits/stdc++.h> //  l   ( 2  ) ,   3

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+5, base = 1e9+7,maxm=1e6+500;

int main()
{
    int n;
   // files1;
   // files2;
    fast_io;
    cin>>n;
    int a = 0, a1 = 0;
    int b,p;
    cin>>b>>p;
    a1 = n*p;
    while (n!=1)
    {
        int m = n;
        int k = 1;
        int k1 = 0;
        while (k<=m)
        {
            k*=2;
            k1++;
        }
        k/=2;

        a += (k/2)*(2*b+ 1) ;
        m = n-k;
        n = m +k/2;
       // cerr<<n<<endl;
    }
    cout<<a<<' '<<a1;
	return 0;

}
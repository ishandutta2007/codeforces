
#include <bits/stdc++.h>
const int maxn=2e5;
const int inf=2e9;
const int eps=1e-8;
const int base=1e9+7;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;
int a[maxn];
int main()
{
    double v1,v2,d,L;
  //          freopen("input.txt","r",stdin);
//             freopen("output.txt","w",stdout);
       cin>>d>>L>>v1>>v2;
        double l = 0, r= 1e7;
        for (int iter = 0;iter<=10000;iter++)
        {
            double m = (l+r)/2;
            if (L-((v1+v2)*m) >= d)
                l = m;
            else
                r = m;
        }

        cout<<fixed<<setprecision(20)<<(l+r)/2;
        return 0;
}
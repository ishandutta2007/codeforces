#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
using namespace std;
typedef long long ll;


ll n,d,kol=-2e9;
long long r=0;
long long ss[100000];
pair <ll, ll> a[100000];

int main()
{

    cin >> n >> d;
    for (int i =0; i < n;i++)
    cin >> a[i].f >> a[i].s;

    sort (a,a+n);

    ss[0]=a[0].s;
    for (int i=1;i<n;i++)
        ss[i]=abs(ss[i-1]+a[i].s);
    for (int i=0;i<n;i++){
            
        while (r<n&&a[i].f+d>a[r].f)
            r++;
        if (ss[r-1]-ss[i]+a[i].s>kol) kol=ss[r-1]-ss[i]+a[i].s;
    }

    cout << kol;
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

long double x[101],y[101];

int main()
{
    int n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    long double ans=0;
    for (int i=1;i<n;i++) ans+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]))/50.0;
    cout.precision(20);
    cout << ans*k << endl;
    return 0;
}
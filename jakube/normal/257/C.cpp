#include<cstdio>
#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define PI 3.14159265
using namespace std;
typedef long long ll;
vector<double> v;
ll power(ll x,ll y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
    
};
pair<double,double> p[100002];
int main()
{
    ll n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lf %lf",&p[i].first,&p[i].second);
    for(i=1;i<=n;i++)
    {
        double k  = atan2(p[i].second,p[i].first) * 180/PI;
        //if(k<0) k = k + 360;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    ll nn = v.size();
    double high = v[nn-1];
    double low = v[0];
    double ans = high - low;
    ll mark = 1;
    for(i=1;i<n;i++)
    {
		double tmp = (360 + v[i-1] - v[i]);
		ans = std::min(tmp, ans);
    }
    printf("%0.9lf",ans);
    return 0;
}
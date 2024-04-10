#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 double v;
 double go(double c,double m,double p)
{
    if(p>0.99999999)return 1;
    double ans=1;
    if(c<0.00000001)
    {

       double u=min(m,v);
        ans+=m*go(c,m-u,p+u);
        return ans;
    }
    if(m<0.00000001)
    {

       double u=min(c,v);
        ans+=c*go(c-u,m,p+u);
        return ans;
    }
       double u=min(c,v);
      ans+= c * go(c-u,m+u/2.0,p+u/2.0);
        u=min(m,v);
    ans+= m*go(c+u/2.0,m-u,p+u/2.0);

   return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        double c,m,p;
        cin>>c>>m>>p>>v;
        cout<<fixed<<setprecision(8)<<go(c,m,p)<<endl;
    }
    return 0;
}
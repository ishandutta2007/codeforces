#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;
set<pair<double,double> > a;
double x[1009],y[1009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)cin>>x[i]>>y[i];
for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++)
if(x[i]==x[j])a.insert(make_pair(10000000,x[i]));
else{double m=(y[i]-y[j])/(x[i]-x[j]);
double p=y[i]-m*x[i];
a.insert(make_pair(m,p));
}
ll s=a.size();
ll ans=(s*(s-1))/2;
double r=0,cn=0;
for(set<pair<double,double> >::iterator it=a.begin();it!=a.end();it++)
{
if((*it).first!=r){ans-=(cn*(cn-1))/2;r=(*it).first;cn=1;}else cn++;

}
ans-=(cn*(cn-1))/2;
cout<<ans;
return 0;
}
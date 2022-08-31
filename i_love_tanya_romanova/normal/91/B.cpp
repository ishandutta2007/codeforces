#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
long n,ar[200000],ans[200000],ps,ps1,tvp;
int main(){
cin>>n;
vector <pair <long,long> > vp;
for (int i=1;i<=n;i++){
cin>>ar[i];pair <long, long> pr=make_pair(ar[i],i);vp.push_back(pr);}

sort(vp.begin(),vp.end());
ps=-100;
ps1=ps;
for (int i=0;i<n;i++)
{
 if (vp[i].first!=tvp){ps=ps1;tvp=vp[i].first;}
 ans[vp[i].second]=ps;//cout<<ps<<" "<<ps1<<" "<<vp[i].second<<endl;
 ps1=max(ps1,vp[i].second);
}
long od=-1;
for (int i=1;i<=n;i++){cout<<max(od,ans[i]-i-1);if (i<n)cout<<" ";else cout<<endl;}
cin.get();cin.get();
return 0;
}
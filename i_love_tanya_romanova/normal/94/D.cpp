/*
When your day is long
And the night, the night is yours alone
When you're sure you've had enough
Of this life, well hang on

Don't let yourself go
'Cause everybody cries
And everybody hurts sometimes

Sometimes everything is wrong
Now it's time to sing along
When your day is night alone (Hold on, hold on)
If you feel like letting go (Hold on)
If you think you've had too much
Of this life, well hang on

Everybody hurts
Take comfort in your friends
Everybody hurts
Don't throw your hand, oh no

Don't throw your hand
If you feel like you're alone
No, no, no, you are not alone

If you're on your own in this life
The days and nights are long
When you think you've had too much of this life to hang on

Well, everybody hurts sometimes
Everybody cries
Everybody hurts sometimes
And everybody hurts sometimes

So hold on, hold on
Hold on, hold on, hold on, hold on, hold on, hold on
Everybody hurts
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
long n,m,w,ps;
double fr[100000],sz[10000];
int main(){
    vector <pair <long, double> > ans[1000];
    vector <pair <long, double> > ans1[1000];
    pair <long, double> p;
    
    cin>>n>>w>>m;
    ps=1;for (int i=1;i<=m;i++)sz[i]=double(w*n)/m;
    for (int i=1;i<=n;i++)fr[i]=w;
    for (int i=1;i<=m;i++)
    {
        while (sz[i]>1e-9)
        {//cout<<ps<<" "<<fr[ps]<<" "<<sz[i]<<endl;cin.get();
        if (sz[i]>=fr[ps]-1e-9){p=make_pair(i,fr[ps]);ans[ps].push_back(p);p=make_pair(ps,fr[ps]);ans1[i].push_back(p);
        sz[i]-=fr[ps];fr[ps]=0;ps++;}
        else {p=make_pair(i,sz[i]);ans[ps].push_back(p);p=make_pair(ps,sz[i]);ans1[i].push_back(p);
        fr[ps]-=sz[i];sz[i]=0;}
              }
    }
long fl=0;
for (int i=1;i<=n;i++)if (ans[i].size()>2)fl++;
if (fl){cout<<"NO"<<endl; return 0;}
cout<<"YES"<<endl;cout.precision(8);
for (int i=1;i<=m;i++){
    for (int j=0;j<ans1[i].size();j++)
    {if (j)cout<<" ";cout<<fixed<<ans1[i][j].first<<" "<<ans1[i][j].second;
    }cout<<endl;}
    
cin.get();cin.get();
return 0;
}
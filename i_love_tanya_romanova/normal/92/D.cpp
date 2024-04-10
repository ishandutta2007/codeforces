/*
In a world polluted inside
let's pretend the nightmare is done
from the earth the magma will rise
From the sea comes cancerous tides
The meaning of life ends in prophecy
Premonitions bring tragedy
is the hope for humanity

Molten fire.. flies through the sky
Burning high... eclipse of the sun
Blackened skies
Rites of the night
The days in darkness in 2012

Mother earth's been withered by time
Already dead and we didn't even know it
Watch the stars to give us a sign
From above, all the angels descend
The meaning of life ends in agony
Raped by impurities
Not chance for humanity

Molten fire.. flies through the sky
Burning high... eclipse of the sun
Blackened skies
Rites of the night
The days in darkness in 2012

Magma splits the earth and shifts below
Molten lava bursts and overflow
Rise as we wait, annihilate
Burning earth pulls to the sun
Rise as we wait, obliterate
Burning earth pulls to the sun
Three days of darkness in 2012

Mega cities still blaze in the night
Burning the ashes they choke
From the earth the magma will rise
Enveloped in poisonous smoke
so the meaning of life ends in prophecy
Premonitions of tragedy
still no hope for humanity

Molten fire.. flies through the sky
Burning high... eclipse of the sun
Blackened skies
Rites of the night
The days in darkness in 2012
*/

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
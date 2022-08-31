/*
Off we sail from Svea shores
To test our steel through out the world
Soon to come a raging battle
The strong will join and the weak shall fall
The army of immortals rise
To seek revenge of all the false
So we raise the hammer high
And call to Odin for a sign...

Join us in this holy war
Against the world and all it stands for
Crush the men of fashion's flow,
The slaves of Christ and the thrells of Islam
Riding on the blackest wind
We can't be stopped, we cannot fail
So we raise the horn of pride
And drink to glory and victory...

Onward into countless battles
We took the crown from sacred land
Soon return to Birka shores
Through storm, rain and hellish waters
Men of power, strength and might
Were born to live forever more
So we raise the hammer high
And call to Thor for a sign...
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 1024

using namespace std;

int n,ar[1<<20];
vector<pair<int, int> > v;
int reach[1<<20],sum[1<<20];
int ans;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    v.clear();
    for (int divs=0;divs<=19;divs++)
    {
        int q=ar[i];
        for (int j=0;q<=1000000;q*=2,j++)
        {
            v.push_back(make_pair(q,divs+j));
            if (q==0)break;
        }
        ar[i]/=2;
    }
    sort(v.begin(),v.end());
    int bst=1e9;
    for (int j=0;j<v.size();j++)
    {
        if (j>0&&v[j].first!=v[j-1].first)
        {
            reach[v[j-1].first]++;
            sum[v[j-1].first]+=bst;
            bst=1e9;
        }
        bst=min(bst,v[j].second);
    }
    reach[v.back().first]++;
    sum[v.back().first]+=bst;
}

ans=1e9;

for (int i=0;i<=1000000;i++)
    if (reach[i]==n)
        ans=min(ans,sum[i]);
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}
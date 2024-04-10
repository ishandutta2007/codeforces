/*
I don't know who I should belong to
All I know is that I don't belong
So if you feel the same that I've always felt
Let's walk this path through flame and flood
Let us be a part of the cure
Never part of the plague
We'll only remembered for what we create
From flood into fire
One thousand voices sing
We're in this together
For whatever fate may bring
I don't know if I could trust you
All I know is that I cannot trust myself
Let's face our imperfections now to connect
Capitulation deserves no respect
Let us be a part of the cure
Never part of the plague
We'll only remembered for what we create
From flood into fire
One thousand voices sing
We're in this together
For whatever fate may bring
No fear of confrontation
And if the waters rise we'll see the cloudless skies
We have to make our choices now
These words that I now write might be all I leave behind
Muses of the lower world
Sing for pain I once endured
Mantic wisdom finding the
Mystery divine
From flood into fire
One thousand voices sing
We're in this together
For whatever fate may bring
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
#define bsize 512

using namespace std;

int n,m,p;
long long d[1<<20];
vector<long long> v;
long long S[1<<20];
pair<long long, long long>  lines[1<<19];
long long dp[105][100005];
int s,t;
long long eval(pair<long long, long long> p, long long x)
{
    return p.first*x+p.second-S[x];
}

double get_inter(pair<long long, long long> p1,pair<long long, long long> p2)
{
    double z=p1.first-p2.first;
    if (z==0)
    {
        return (p1.second>p2.second?1e18:-1e18);
    }
    return (p2.second-p1.second)/z;
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>p;
for (int i=1;i<n;i++)
{
    int temp;
    cin>>temp;
    d[i+1]=d[i]+temp;
}

for (int i=1;i<=m;i++)
{
    long long h,t;
    cin>>h>>t;
    h=t-d[h];
    v.push_back(h);
}
/*
for (int i=0;i<m;i++)
{
    int q;
    cin>>q;
    v.push_back(q);
}*/
sort(v.begin(),v.end());

reverse(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    S[i+1]=S[i]+v[i];
}

for (int i=0;i<=p;i++)
    for (int j=0;j<=m;j++)
        dp[i][j]=1e18;

dp[0][0]=0;
/*
for (int i=0;i<v.size();i++)
    cout<<"@"<<v[i]<<" ";
cout<<endl;
*/
for (int lev=1;lev<=p;lev++)
{
    s=t=0;
    dp[lev][0]=0;
    
    for (int i=1;i<=m;i++)
    {
        pair<long long, long long> tp;
        long long val;
        
        // (j-i+1)*(v[i-1])-(s[j]-s[i-1])+dp...
        
        tp=make_pair(v[i-1],S[i-1]+v[i-1]*(1-i)+dp[lev-1][i-1]);
        
        while (t>s+1&&get_inter(tp,lines[t-1])<get_inter(lines[t-1],lines[t-2]))
        {
        //  cout<<get_inter(tp,lines[t-1])<<"  "<<get_inter(lines[t-1],lines[t-2])<<" &"<<s<<" "<<t<<endl;
            --t;
        }
        
        
        if (t==s||get_inter(tp,lines[t-1])<1e16)
        {
        lines[t]=tp;
        ++t;
        }
        
        
        while (true)
        {
            if (s+1==t)
            {
                break;
            }
            if (get_inter(lines[s],lines[s+1])<i)
                ++s;
            else
                break;
        }
            
        tp=lines[s];
        
        val=eval(tp,i);
        dp[lev][i]=val;
        
        //cout<<lines[s].first<<"# "<<lines[s].second<<endl;
        
        /*
        for (int q=s;q<t;q++)
        {
            cout<<lines[q].first<<"   "<<lines[q].second<<endl;
            if (q+1<t)
                cout<<get_inter(lines[q],lines[q+1])<<endl;
        }
        cout<<endl;*/
    }
/*  for (int j=1;j<=m;j++)
        cout<<dp[lev][j]<<" ";
    cout<<endl;*/
}

cout<<dp[p][m]<<endl;
/*
for (int i=0;i<=p;i++)
    for (int j=0;j<=m;j++)
    {
        dp[i][j]=1e18;
    }

for (int i=0;i<=p;i++)
    dp[i][0]=0;

for (int i=1;i<=p;i++)
    for (int j=1;j<=m;j++)
        for (int q=j;q<=m;q++)
            dp[i][q]=min(dp[i][q],dp[i-1][j-1]+S[q]-S[j-1]-v[j-1]*(q-j+1));

cout<<dp[p][m]<<endl;
*/
//cin.get();cin.get();
return 0;}
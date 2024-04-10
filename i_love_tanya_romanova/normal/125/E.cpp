/*
And when life seems to be complete
It comes and knocks us off our feet
The element of surprise
The vengeful attack
Straight on your back it will send you
Into a state of deja-vu
Here it comes one more time
Showing its ugly face

Assaulting the senses
Screaming into the mind
Premeditating master plans
No need to underestimate

Prepare for what you cannot see
Expect the unexpected
And you will save yourself a state of shock
A waiting game, waiting to see
Expect the unexpected
And you will save yourself a state of shock

Another lesson learned to go with the others
That sit and wait to see
A silent voice

It doesn't matter who you are
In this sense we're all the same
To taste tranquility would be ecstasy
I'm holding on with all my might
To this ride we call life
Strapped down to clarity
Surprised no more
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

int n,m,k;
int a[1<<20],b[1<<20],c[1<<20];
double l,r;
vector<int> ans,tans;

int eval()
{
    int res=0;
    for (int i=0;i<tans.size();i++)
    {
        int id=tans[i];
        if (a[id]==1||b[id]==1)
            ++res;      
    }
    return res;
}

int w[1<<20];

int get(int x)
{
    if (x==w[x])
        return x;
    return w[x]=get(w[x]);
}

void merge(int a,int b)
{
    w[a]=b;
}

vector<pair<double,int> > E;


void mst(double pen)
{
    E.clear();
    tans.clear();
    for (int i=1;i<=m;i++)
    {
        double tcost=c[i];
        if (a[i]==1||b[i]==1)
            tcost+=pen;
        E.push_back(make_pair(tcost,i));
    }
    sort(E.begin(),E.end());
    for (int i=1;i<=n;i++)
        w[i]=i;
    
    for (int i=0;i<E.size();i++)
    {
        int id=E[i].second;
        int v1,v2;
        v1=a[id];
        v2=b[id];
        v1=get(v1);
        v2=get(v2);
        if (v1==v2)
            continue;
        tans.push_back(id);
        merge(v1,v2);
    }
    
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=m;i++)
{
    cin>>a[i]>>b[i]>>c[i];
}

l=-1000000;
r=1000000;
for (int iter=1;iter<=77;iter++)
{
    double mid=l+r;
    mid/=2;
    mst(mid);
    if (eval()<k)
        r=mid;
    else
    {
        l=mid;
        if (eval()==k)
            ans=tans;
    }
}

tans=ans;
if (eval()!=k||ans.size()!=n-1)
{
    cout<<-1<<endl;
    return 0;
}

cout<<n-1<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)
        cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}
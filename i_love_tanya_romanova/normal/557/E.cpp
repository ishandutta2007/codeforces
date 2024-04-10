/*
When I look into your eyes it keeps me together
When I hear your private lies I don't feel any better
Clouds will gather over me,
Rain will soak me down ,
As I remember, my December
Just to the tell, upon what is tell
On the left side of the dawn
Leaving the the traces, forgotten the faces
Of the last December morn
Nothing but hte truth is all I wanted
Everything I had was always counted
Clouds will gather over me,
Lightening strike me down,
As I remember my, my december
From the hand of god that squeeze me
To the firestorm that feeds me
In my December
In a world too much
For the likes of man
Who can't remember
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

int n;
string st;
bool good[5005][5005];
int cnt;
int l[13000000],r[13000000],here[13000000],ttl[13000000];
int cur;
int need;

void move_l()
{
    if (l[cur]==0)
    {
        ++cnt;
        l[cur]=cnt;
    }
    cur=l[cur];
}
void move_r()
{
    if (r[cur]==0)
    {
        ++cnt;
        r[cur]=cnt;
    }
    cur=r[cur];
}

void dfs(int v)
{
    if (l[v]!=0)
    {
        dfs(l[v]);
        ttl[v]+=ttl[l[v]];
    }
    
    if (r[v]!=0)
    {
        dfs(r[v]);
        ttl[v]+=ttl[r[v]];
    }
    ttl[v]+=here[v];
}

void solve(int v)
{
/*  cout<<v<<"  "<<here[v]<<" "<<need<<" "<<l[v]<<" "<<r[v]<<endl;
    cin.get();
*/
    if (here[v]>=need)
    {
        return;
    }
    need-=here[v];
    
    if (l[v]!=0)
    {
        if (ttl[l[v]]<need)
        {
            cout<<"b";
            need-=ttl[l[v]];
            solve(r[v]);
        }
        else
        {
            cout<<"a";
            solve(l[v]);
        }
    }
    else
    {
        cout<<"b";
        solve(r[v]);
    }
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
n=st.size();
for (int r=0;r<n;r++)
{
    for (int l=r;l>=0;--l)
    {
        if (st[l]!=st[r])
            continue;
        if (l+2>r-2||good[l+2][r-2]==1)
            good[l][r]=1;
    }
}

/*
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    cout<<good[i][j]<<" ";
    cout<<endl;
}*/

cnt=1;

for (int i=0;i<n;i++)
{
    cur=1;
    for (int j=i;j<n;j++)
    {
    //  cout<<cur<<"@"<<l[cur]<<" "<<r[cur]<<" "<<i<<" "<<j<<endl;
        
        if (st[j]=='a')
            move_l();
        else
            move_r();
        if (good[i][j])
            here[cur]++;
    }
}

dfs(1);

cin>>need;
solve(1);

//cin.get();cin.get();
return 0;}
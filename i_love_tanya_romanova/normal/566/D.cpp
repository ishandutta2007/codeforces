/*
Insane hunger, cold heart beating
Intense bloodlust, pressure increasing
All excited at every reek of death
Stop at nothing, must feed from human flesh
Insane for blood
Insane for blood
The frustration keeps on peaking
Internal torment pain comes creeping
The night's falling must seek another prey
A new source of blood to live another day
Insane for blood
Insane for blood
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

/*
int Get(int x)
{
    if (w[x]==x)
        return x;
    return w[x]=Get(w[x]);
}

void Merge(int a,int b)
{
    if (rand()%2)
        swap(a,b);
    w[a]=b;
}

void build(int v,int l,int r)
{
    topush[v]=1e9;
    
    if (l==r)
    {
        flag[v]=1;
        t[v]=l;
        return;
    }
    int m=l+r;
    m/=2;
    build(v*2,l,m);
    build(v*2+1,m+1,r);
    t[v]=min(t[v*2],t[v*2+1]);
}

void push(int v,int l,int r)
{
    int m=l+r;
    m/=2;
    t[v*2]=min(t[v*2],topush[v]);
    t[v*2+1]=min(t[v*2+1],topush[v]);
    topush[v*2]=min(topush[v*2],topush[v]);
    topush[v*2+1]=min(topush[v*2+1],topush[v]);
}

int get(int v,int tl,int tr,int l,int r)
{
    if (l>r)
        return 1e9;
    if (tl==l&&tr==r)
        return t[v];
    
    push(v,tl,tr);
    
    int tm=tl+tr;
    tm/=2;
    return min(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int l,int r,int val)
{
    if (l>r)
        return ;
    if(l==tl&&r==tr)
    {
        t[v]=min(t[v],val);
        topush[v]=min(topush[v],val);
        return ;
    }
    push(v,tl,tr);
    int tm=tl+tr;
    tm/=2;
    update(v*2,tl,tm,l,min(r,tm),val);
    update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
    t[v]=min(t[v*2],t[v*2+1]);
}
*/
int n,tests,w[1<<20];
vector<int> vec[1<<20];
int sz[1<<20];
int r[1<<20];

int get_right(int x)
{
    if (w[r[x]]!=w[x])
    {
        return r[x];
    }
    return r[x]=get_right(r[x]);
}

void merge(int a,int b)
{
    if (vec[a].size()>vec[b].size())
        swap(a,b);
    for (int i=0;i<vec[a].size();i++)
    {
        int id=vec[a][i];
        vec[b].push_back(id);
        w[id]=b;
    }
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

//cin>>n>>tests;
/*
scanf("%d",&n);
scanf("%d",&tests);

for (int i=1;i<=n;i++)
{
    w[i]=i;
}

build(1,1,n);

for (;tests;--tests)
{
    int tp;
    int a,b;
    scanf("%d",&tp);
    scanf("%d",&a);
    scanf("%d",&b);
    
    if (tp==1)
    {
        int ta,tb;
        ta=tb=1e9;
        ta=get(1,1,n,a,a);
        tb=get(1,1,n,b,b);
        cout<<"@"<<ta<<"  % "<<tb<<endl;
        //ta=min(ta,tb);
        update(1,1,n,a,a,min(ta,tb));
        update(1,1,n,b,b,min(ta,tb));
        ta=Get(ta);
        tb=Get(tb);
        cout<<""<<ta<<" "<<tb<<endl;
        Merge(ta,tb);
    }
    if (tp==2)
    {
        int x=get(1,1,n,a,b);
        x=Get(x);
        cout<<"@"<<x<<endl;
        update(1,1,n,a,b,x);
    }
    if (tp==3)
    {
        a=get(1,1,n,a,a);
        b=get(1,1,n,b,b);
        a=Get(a);
        b=Get(b);
        cout<<a<<" !  "<<b<<endl;
        if (a==b)
            puts("YES");
        else
            puts("NO");
        
    }
}
*/

scanf("%d",&n);
scanf("%d",&tests);
for (int i=1;i<=n;i++)
{
    w[i]=i;
    sz[i]=1;
    r[i]=i+1;
    vec[i].push_back(i);
}

for (;tests;--tests)
{
    int tp,a,b;
    scanf("%d",&tp);
    scanf("%d",&a);
    scanf("%d",&b);
    if (tp==3)
    {
        if (w[a]==w[b])
            puts("YES");
        else
            puts("NO");
    }
    if (tp==1)
    {
        if (w[a]==w[b])
        {
            continue;
        }
        merge(w[a],w[b]);
    }
    if (tp==2)
    {
        while (a<=b)
        {
            int ta=get_right(a);
            if (ta>b)
                break;
            merge(w[a],w[ta]);
            a=ta;
        }
    }
}
//cin.get();cin.get();
return 0;}
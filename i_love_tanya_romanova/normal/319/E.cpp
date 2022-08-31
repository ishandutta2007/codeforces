/*
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

int tp[1<<20],a[1<<20],b[1<<20];
vector<int> x;
map<int,int> mapp;
int n;
int N,cnt;
int w[1<<20];
vector<int> items[1<<20];
int L[1<<20],R[1<<20];
int ID;

int get(int x)
{
    if (x==w[x])
        return x;
    return w[x]=get(w[x]);
}

void merge(int a,int b)
{
    a=get(a);
    b=get(b);
    if (a==b)return;
    
    w[a]=b;
    L[b]=min(L[b],L[a]);
    R[b]=max(R[b],R[a]);
}

void run_merges(int v,int tl,int tr,int x)
{
    for (int i=0;i<items[v].size();i++)
    {
        merge(cnt,items[v][i]);
    }
    items[v].clear();
    
    if (tl==tr)
        return; 
    int tm=tl+tr;
    tm/=2;
    if (x<=tm)
        run_merges(v*2,tl,tm,x);
    else
        run_merges(v*2+1,tm+1,tr,x);
}

void add_item(int v,int tl,int tr,int l,int r)
{
    if (l>r)return;
    if (tl==l&&tr==r)
    {
        items[v].push_back(ID);
        return;
    }
    int tm=tl+tr;
    tm/=2;
    add_item(v*2,tl,tm,l,min(r,tm));
    add_item(v*2+1,tm+1,tr,max(tm+1,l),r);
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>tp[i]>>a[i]>>b[i];
    if (tp[i]==1)
    {
    x.push_back(a[i]);
    x.push_back(b[i]);
    }
}

sort(x.begin(),x.end());

for (int i=0;i<x.size();i++)
{
    if (i==0||x[i]!=x[i-1])
    {
        mapp[x[i]]=++cnt;
    }
}

cnt=0;

int N=n*2;

for (int i=1;i<=n;i++)
{
    if (tp[i]==2)// get
    {
        a[i]=get(a[i]);
        b[i]=get(b[i]);
        if (a[i]==b[i])
        {
            cout<<"YES"<<endl;
            continue;
        }
        if (L[a[i]]>=L[b[i]]&&R[a[i]]<=R[b[i]])
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    else
    {
        ++cnt;
        a[i]=mapp[a[i]];
        b[i]=mapp[b[i]];
        
        L[cnt]=a[i];
        R[cnt]=b[i];
        w[cnt]=cnt;
        
        int tl,tr;
        tl=L[cnt];
        tr=R[cnt];
        
        run_merges(1,1,N,tl);
        run_merges(1,1,N,tr);
        
        ID=cnt;
        ID=get(ID);
        
        if (L[ID]<R[ID]-1)
            add_item(1,1,N,L[ID]+1,R[ID]-1);
    }
}

//cin.get();cin.get();
return 0;}
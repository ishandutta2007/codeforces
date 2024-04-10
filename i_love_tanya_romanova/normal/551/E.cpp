/*
The circling ravens are hunting us down
Erudite playthings who lost what we found
But I don't care

Hollow illusions fallen from grace
To a land of confusion there's no such place
And you won't go anywhere
And no-one cares
Avalon nation where is your station now
Because everyone wants to go home
But can't find the way

Honesty hides in the dust of the afterglow
Scattered so wide but we know what we have to know
Lost in the view but ignoring your colophon
Longing to lose our illusion of counting on you
Did you do all the things that you wanted to do
Nobody noticed the war of the worlds
A paradise broken a planet disturbed
So unaware
The carrion ravens are down for the feast
To feed on the broken the lost and the least
Before they go anywhere
And no-one cares

Babylon nation who's going to save you now
Because everyone opened their homes
And closed off the way
Honesty hides in the dust of the afterglow
Scattered so wide but we know what we have to know
Lost in the view but ignoring your colophon
Longing to lose our illusion of counting on you
But I'm counting on you I'm counting on you
Did you do all the things that you wanted to do
Every image bears the imprint of the master
And the message is the way to ever after
Did you do all the things that you wanted to do
Did you do all the things that you wanted to do
Did you do all the things that you wanted to do
Did you do all the things that you wanted to do
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
#define bsize 256

using namespace std;

int n,tests,ar[1<<20];
vector<pair<int, int> >block[1<<20];
int l,r,val;
int tp;
int onblock[1<<20];

void rebuild(int bl,int l,int r,int val)
{
    for (int i=0;i<block[bl].size();i++)
    {
        if (block[bl][i].second>=l&&block[bl][i].second<=r)
            block[bl][i].first+=val;
        if (block[bl][i].first>1e9+1e7)
            block[bl][i].first=1e9+1e7;
    }
    sort(block[bl].begin(),block[bl].end());
}

void naive_update(int l,int r,int val)
{
    for (int i=l;i<=r;i++)
     ar[i]+=val;
}

int naive(int val)
{
    int l,r;
    l=1e9;
    r=-1e9;
    for (int i=0;i<n;i++)
     if( ar[i]==val)
     {
        l=min(l,i);
        r=max(r,i);
     }
     if (l>r)return -1;
    return r-l;
}
void update(int l,int r,int val)
{
    rebuild(l/bsize,l,r,val);
    if (r/bsize!=l/bsize)
    rebuild(r/bsize,l,r,val);
    
    for (int i=l/bsize+1;i<r/bsize;i++)
        {
            onblock[i]+=val;
            if (onblock[i]>1e9+1e7)
                onblock[i]=1e9+1e7;
        }
    
}

int get_first(int bl,int val)
{
    int l,r;
    l=0;
    r=block[bl].size()-1;
    while (l<r)
    {
        int mid=l+r;
        mid/=2;
        if (block[bl][mid].first<val)
            l=mid+1;
        else r=mid;
    }
    if (block[bl][l].first!=val)
        return -1;
    return block[bl][l].second;
}

int get_last(int bl,int val)
{
    int l,r;
    l=0;
    r=block[bl].size()-1;
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        if (block[bl][mid].first<=val)
            l=mid;
        else r=mid-1;
    }
    if (block[bl][l].first!=val)
        return -1;
    return block[bl][l].second;
}

pair<int, int> merg(pair<int, int> p1,pair<int, int> p2)
{
    p1.first=min(p1.first,p2.first);
    p1.second=max(p1.second,p2.second);
    return p1;
}

pair<int, int> partial(int bl,int l,int r,int val)
{
    val-=onblock[bl];
    pair<int, int> tp=make_pair(1e9,-1e9);
    for (int i=0;i<block[bl].size();i++)
    {
        if (block[bl][i].first==val&&block[bl][i].second>=l&&block[bl][i].second<=r)
            tp.first=min(tp.first,block[bl][i].second),
            tp.second=max(tp.second,block[bl][i].second);
    }
    return tp;
}

int solve(int l,int r,int val)
{
    pair<int, int> tp=make_pair(1e9,-1e9);
    tp=merg(tp,partial(l/bsize,l,r,val));
    tp=merg(tp,partial(r/bsize,l,r,val));
//  cout<<"%"<<endl;
    for (int i=l/bsize+1;i<r/bsize;i++)
    {
        int val1,val2;
        int need=val-onblock[i];
        val1=get_first(i,need);
        val2=get_last(i,need);
        if (val1!=-1)
            tp.first=min(tp.first,val1);
        if (val2!=-1)
            tp.second=max(tp.second,val2);
    }
    if (tp.first>tp.second)
        return -1;
    return tp.second-tp.first;
}

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;

for (int i=0;i<n;i++)
{
    cin>>ar[i];
}

for (int i=n;i<=n+bsize;i++)
 ar[i]=1e9+1e6;
 
int blocks=n/bsize+(n%bsize>0);

for (int i=0;i<n;i+=bsize)
{
    for (int j=i;j<i+bsize;j++)
    {
        block[i/bsize].push_back(make_pair(ar[j],j));
    }
    sort(block[i/bsize].begin(),block[i/bsize].end());
    
}

for (;tests;--tests)
{
    cin>>tp;
    if (tp==1)
    {
        cin>>l>>r>>val;
        --l;
        --r;
        update(l,r,val);
    //  naive_update(l,r,val);
        continue;
    }
    cin>>val;
    cout<<solve(0,n-1,val)<<endl;
//  cout<<naive(val)<<endl;
}

//cin.get();cin.get();
return 0;}
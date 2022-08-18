/*
Put a candle in the window, 'cause I feel I've got to move.
Though I'm going, going, I'll be coming home soon,
'Long as I can see the light.

Pack my bag and let's get movin', 'cause I'm bound to drift a while.
When I'm gone, gone, you don't have to worry long,
'Long as I can see the light.

Guess I've got that old trav'lin' bone, 'cause this feelin' won't leave me alone.
But I won't, won't be losin' my way, no, no
'Long as I can see the light.

Yeah! Yeah! Yeah! Oh, Yeah!

Put a candle in the window, 'cause I feel I've got to move.
Though I'm going, going, I'll be coming home soon,
Long as I can see the light.
Long as I can see the light.
Long as I can see the light.
Long as I can see the light.
Long as I can see the light.
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

int n,tests,x[1<<20],y[1<<20];
string tp[1<<20];
vector<int> xs,ys;
map<int, int> mx,my;
int cx,cy;
int rmx[1<<20],rmy[1<<20];
int tx[1<<20],ty[1<<20];
set<pair<int, int> > did;

void buildX(int v,int tl,int tr)
{
    if (tl==tr)
    {
        tx[v]=1e9+1e7;
        return;
    }
    int tm=tl+tr;
    tm/=2;
    buildX(v*2,tl,tm);
    buildX(v*2+1,tm+1,tr);
    tx[v]=1e9+1e7;
}

void buildY(int v,int tl,int tr)
{
    if (tl==tr)
    {
        ty[v]=1e9+1e7;
        return;
    }
    int tm=tl+tr;
    tm/=2;
    buildY(v*2,tl,tm);
    buildY(v*2+1,tm+1,tr);
    ty[v]=1e9+1e7;
}

void updateX(int v,int tl,int tr,int ps,int val)
{
    if (tl==tr)
    {
        tx[v]=val;
        return;
    }
    int tm=tl+tr;
    tm/=2;
    if (ps<=tm)
        updateX(v*2,tl,tm,ps,val);
    else
        updateX(v*2+1,tm+1,tr,ps,val);
    tx[v]=min(tx[v*2],tx[v*2+1]);
}

void updateY(int v,int tl,int tr,int ps,int val)
{
    if (tl==tr)
    {
        ty[v]=val;
        return;
    }
    int tm=tl+tr;
    tm/=2;
    if (ps<=tm)
        updateY(v*2,tl,tm,ps,val);
    else
        updateY(v*2+1,tm+1,tr,ps,val);
    ty[v]=min(ty[v*2],ty[v*2+1]);
}

int getX(int v,int tl,int tr,int l,int r)
{
    if (l>r)return 1e9+1e8;
    if (tl==l&&tr==r)
        return tx[v];
    int tm=tl+tr;
    tm/=2;
    return min(getX(v*2,tl,tm,l,min(r,tm)),getX(v*2+1,tm+1,tr,max(l,tm+1),r));
}

int getY(int v,int tl,int tr,int l,int r)
{
    if (l>r)return 1e9+1e8;
    if (tl==l&&tr==r)
        return ty[v];
    int tm=tl+tr;
    tm/=2;
    return min(getY(v*2,tl,tm,l,min(r,tm)),getY(v*2+1,tm+1,tr,max(l,tm+1),r));
}


int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;

for (int i=1;i<=tests;i++)
{
    cin>>x[i]>>y[i];
    cin>>tp[i];
    xs.push_back(x[i]);
    ys.push_back(y[i]);
}

xs.push_back(0);
ys.push_back(0);

sort(xs.begin(),xs.end());
sort(ys.begin(),ys.end());

for (int i=0;i<xs.size();i++)
{
    if (i==0||xs[i]!=xs[i-1])
    {
        ++cx;
        mx[xs[i]]=cx;
        rmx[cx]=xs[i];
    }
}

for (int i=0;i<ys.size();i++)
{
    if (i==0||ys[i]!=ys[i-1])
    {
        ++cy;
        my[ys[i]]=cy;
        rmy[cy]=ys[i];
    }
}

//cout<<"@"<<endl;

buildX(1,1,cx);
buildY(1,1,cy);

updateX(1,1,cx,1,0);
updateY(1,1,cy,1,0);

for (int i=1;i<=tests;i++)
{
    if (did.find(make_pair(x[i],y[i]))!=did.end())
    {
        cout<<0<<endl;
        continue;
    }
    did.insert(make_pair(x[i],y[i]));
    
    if (tp[i]=="U")
    {
        int l,r;
        l=1;
        r=my[y[i]]-1;
        while (l<r)
        {
            int mid=l+r+1;
            mid/=2;
            if (getY(1,1,cy,mid,r)<=x[i])//fine,lock
                l=mid;
            else
                r=mid-1;
        }
        cout<<y[i]-rmy[l]<<endl;
        updateX(1,1,cx,mx[x[i]],rmy[l]);
    }
    else// cp
    {
        int l,r;
        l=1;
        r=mx[x[i]]-1;
        while (l<r)
        {
            int mid=l+r+1;
            mid/=2;
            if (getX(1,1,cx,mid,r)<=y[i])//fine,lock
                l=mid;
            else
                r=mid-1;
        }
        cout<<x[i]-rmx[l]<<endl;
        updateY(1,1,cy,my[y[i]],rmx[l]);
    }
}

//cin.get();cin.get();
return 0;}
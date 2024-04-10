/*
Shadows return showing images of bitter memories
As clear as a sheet of glass
Games have died false beauty won't last
Greed and hatred, some will live
Left to wonder why
Confused, lost, alone pressure now unleashed
See from my point of view
Vengeance for what you do
Issues have been long forgotten
Lost, abandoned, Suffer as I do

Torment and mention, ungodly choices
Act of violence, Pain in now real

Why decide right or wrong
There is another way
You must decide for your own self
The path in which to go

Greed and hatred some will live; Left to wonder why
You will forever
Suffer aching pain pressure now unleashed
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

int n,m;
vector<vector<int> > d;

vector<vector<int> > mult(vector<vector<int> > a,vector<vector<int> > b)
{
    vector<vector<int> > res;
    res=a;
    for (int i=0;i<n;i++)
        for (int k=0;k<n;k++)
            for (int j=0;j<n;j++)
                res[i][j]=max(res[i][j],a[i][k]+b[k][j]);
    return res;
}

vector<vector<int> > pw(vector<vector<int> > a,int b)
{
    if (b==1)
        return a;
    if (b%2)
        return mult(a,pw(a,b-1));
    return pw(mult(a,a),b/2);
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
d.resize(n);

for (int i=0;i<n;i++)
{
    d[i].resize(n);
}

for (int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
        d[i][j]=-1e9;
}

for (int i=0;i<n;i++)
    d[i][i]=0;

for (int i=0;i<m;i++)
{
    int a,b,c,D;
    cin>>a>>b>>c>>D;
    --a;
    --b;
    d[a][b]=max(d[a][b],c);
    d[b][a]=max(d[b][a],D);
}

int l,r;
l=1;
r=n+1;
while (l<r)
{
    int mid=l+r;
    mid/=2;
//  cout<<l<<"  "<<r<<" #"<<mid<<endl;
    vector<vector<int> > D=pw(d,mid);
    
    /*for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<D[i][j]<<" ";
        cout<<endl;
    }
    */
    
    int found=0;
    for (int i=0;i<n;i++)
        if (D[i][i]>0)
            found=1;
    if (found)
        r=mid;
    else
        l=mid+1;
    //cout<<"#"<<found<<" $"<<mid<<endl;
}
if (l>n)
    l=0;

cout<<l<<endl;

//cin.get();cin.get();
return 0;}
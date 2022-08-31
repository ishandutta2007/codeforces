/*
All right
You metalheads
Get on your feet
'n dance with the dead
Gonna raise hell
Yeah hell's unleashed
Don't need no mortal cure
For our release
Come on bang your heads
Yeah, bang your heads
Come on bang your heads
True metalheads
Hell yeah
That's how it goes
Rock hard and heavy
At every show
All true as steel
Metal is our game
We're goin' sick tonight
Don't feel no shame
Come on bang your heads
Yeah, bang your heads
Come on bang your heads
True metalheads
Come on bang your heads
Yeah, bang your heads
Come on bang your heads
True metalheads
Gonna crush the souls of those who disbelieve
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

struct pt
{
    long long x;
    long long y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

long long get_area(pt p1,pt p2,pt p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

long long F(long long x)
{
    if (x<0)
        return -x;
    return x;
}

bool inside(pt p1,pt p2,pt p3,pt p)
{
    long long S=F(get_area(p1,p2,p3));
    S-=F(get_area(p1,p2,p));
    S-=F(get_area(p1,p3,p));
    S-=F(get_area(p2,p3,p));
    return (S==0);
}
vector<pt> convex_hull (vector<pt>  a) {
    if (a.size() == 1)  return a;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
    return a;
}

int n,m;
int trash;
pt V[1<<20];
vector<pt> v;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>trash>>trash;

for (int i=1;i<=n;i++)
{
    cin>>V[i].x>>V[i].y;
}

pt temp;
temp.x=temp.y=0;
long long maxx=0;
long long maxy=0;

v.push_back(temp);
for (int i=1;i<=m;i++)
{
    pt temp;
    cin>>temp.x>>temp.y;
    maxx=max(maxx,temp.x);
    maxy=max(maxy,temp.y);
    v.push_back(temp);
}
temp.x=maxx;
temp.y=0;
v.push_back(temp);
temp.y=maxy;
temp.x=0;
v.push_back(temp);

v=convex_hull(v);
/*for (int i=0;i<v.size();i++)
{
    cout<<v[i].x<<" "<<v[i].y<<endl;
}*/

int found=0;

for (int i=1;i<=n;i++)
{
    int l,r;
    
    l=1;
    r=v.size()-1;
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        long long ta=get_area(v[0],v[mid],V[i]);
        if (ta>0)
            r=mid-1;
        else
            l=mid;
    }
    //cout<<v[0].x<<" "<<v[0].y<<" "<<v[l].x<<" "<<v[l].y<<" "<<v[l+1].x<<" "<<v[l+1].y<<" "<<V[i].x<<" "<<V[i].y<<" "<<inside(v[0],v[l],v[l+1],V[i])<<endl;
    if (inside(v[0],v[l],v[l+1],V[i])==0||get_area(v[l],v[l+1],V[i])==0)
        found=1;
}

if (found)
    cout<<"Max"<<endl;
else
    cout<<"Min"<<endl;
    
//cin.get();cin.get();
return 0;}
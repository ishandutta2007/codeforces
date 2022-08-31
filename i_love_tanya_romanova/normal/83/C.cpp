/*
In a darkened room
Beyond the reach of God's faith
Lies the wounded, the shattered
remains of love betrayed
And the innocense of a child is bought
and sold
In the name of the damned
The rage of the angels left silent
and cold

Forgive me please for I know not
what I do
How can I keep inside the hurt
I know is true

Tell me when the kiss of love
becomes a lie
That bears the scar of sin too deep
To hide behind this fear of running
unto you
Please let there be light
In a darkened room

All the precious times have been put
to rest again
And the smile of the dawn
Brings tainted lust singing my requiem
Can I face the day when I'm tortured
in my trust
And watch it crystalize
While my salvation crumples to dust

Why can't I steer the ship before
it hits the storm
I've fallen to the sea but still
I swim for shore

Tell me when the kiss of love
becomes a lie
That bears the scar of sin too deep
To hide behind this fear of running
unto you
Please let there be light
In a darkened room
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

int n,m,k;
char board[3000][3000];
int si,sj,fi,fj;
bool found;
string ans;

bool outside(int x,int y)
{
    return (x<1||x>n||y<1||y>m);
}
int bits(int x)
{
    if(x==0)return 0;
    return bits(x/2)+x%2;
}

struct node
{
    int x,y,mask;
    string way;
    bool operator<(const node &other)const
    {
        if (way.length()!=other.way.length())
            return way.length()>other.way.length();
        return way>other.way;
    }
};

int sx,sy;
set<int> done[55][55];
priority_queue<node> qu;
vector<int> dx,dy;
int smask[55][55];

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

dx.push_back(0);
dx.push_back(0);
dx.push_back(1);
dx.push_back(-1);
dy.push_back(-1);
dy.push_back(1);
dy.push_back(0);
dy.push_back(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
{
    string st;
    cin>>st;
    for (int j=1;j<=m;j++)
    {
        board[i][j]=st[j-1];
        if (board[i][j]=='S')
        {
            si=i;
            sj=j;
        }
        if (board[i][j]=='T')
        {
            fi=i;
            fj=j;
        }
    }
}

node temp;
temp.x=si;
temp.y=sj;
temp.mask=0;
temp.way="";
qu.push(temp);

found=0;

while (qu.size())
{
    node cur=qu.top();
    qu.pop();
    int qx=cur.x;
    int qy=cur.y;
//  cout<<cur.x<<" "<<cur.y<<" "<<cur.way<<endl;
    if (found)break;
    for (int dir=0;dir<4;dir++)
    {
        int nx=qx+dx[dir];
        int ny=qy+dy[dir];
        if (outside(nx,ny))continue;
        if (board[nx][ny]=='S')continue;
        if (board[nx][ny]=='T'&&found==0)
        {
            found=1;
            ans=cur.way;
            break;
        }
//      cout<<nx<<" "<<ny<<endl;
        int nmask=(cur.mask|(1<<(board[nx][ny]-'a')));
        if (bits(nmask)>k)continue;
        if (done[nx][ny].find(nmask)!=done[nx][ny].end())continue;
        
        if ((smask[nx][ny]&nmask)==smask[nx][ny]&&smask[nx][ny]>0)
            continue;
        smask[nx][ny]=nmask;
        
        done[nx][ny].insert(nmask);
        
        temp.x=nx;
        temp.y=ny;
        temp.mask=nmask;
        temp.way=cur.way+board[nx][ny];
        qu.push(temp);
    }
}

if (found==0)
    cout<<-1<<endl;
else
    cout<<ans<<endl;
    
//cin.get();cin.get();
return 0;}
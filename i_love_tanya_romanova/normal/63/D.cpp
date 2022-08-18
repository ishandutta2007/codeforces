/*
Time, it needs time
To win back your love again
I will be there, I will be there
Love, only love
Can bring back your love someday
I will be there, I will be there

I'll fight, babe, I'll fight
To win back your love again
I will be there, I will be there
Love, only love
Can break down the wall someday
I will be there, I will be there

If we'd go again
All the way from the start
I would try to change
The things that killed our love
Your pride has built a wall, so strong
That I can't get through
Is there really no chance
To start once again
I'm loving you

Try, baby try
To trust in my love again
I will be there, I will be there
Love, our love
Just shouldn't be thrown away
I will be there, I will be there

If we'd go again
All the way from the start
I would try to change
The things that killed our love
Your pride has built a wall, so strong
That I can't get through
Is there really no chance
To start once again

If we'd go again
All the way from the start
I would try to change
The things that killed our love
Yes, I've hurt your pride, and I know
What you've been through
You should give me a chance
This can't be the end
I'm still loving you
I'm still loving you, I need your love
I'm still loving you
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long a,b,c,d,used;
long arp[2000][2000];long ok;
long n,lim,dwn[2000],s,q;


bool inside(long x,long y)
{
 if (y>=1&&y<=a)return (x>=1&&x<=b);
 if (y>a&&y<=a+c)return (x>=1&&x<=d);
 return 0;
}

void solve(long x,long y)
{
 ++used;
 arp[x][y]=used;
 if (inside(x-1,y)&&arp[x-1][y]==0)
 {solve(x-1,y);return;}    
 if (inside(x+1,y)&&arp[x+1][y]==0)
 {solve(x+1,y);return;}    
 
 if (inside(x,y-1)&&arp[x][y-1]==0)
 {solve(x,y-1);return;}    
 if (inside(x,y+1)&&arp[x][y+1]==0)
 {solve(x,y+1);return;}    
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>a>>b>>c>>d;

for (int i=1;i<=b;i++)
for (int j=1;j<=a;j++)
{
 if (ok)continue;
 used=0;
 for (int q=1;q<=a+c;q++)
  for (int w=1;w<=b+d;w++)
   arp[w][q]=0;
 solve(i,j); 
 if (used==a*b+c*d){ok=1;}  
}

cout<<"YES"<<endl;
cin>>n;

for (int i=1;i<=n;i++)
{
    cin>>lim;
    dwn[i]=s;
    s+=lim;
}

/*for (int i=1;i<=3;i++)
cout<<dwn[i]<<" ";
cout<<endl;
*/
dwn[n+1]=100500;

for (int i=1;i<=max(b,d);i++)
{
    for (int j=1;j<=c+a;j++)
    {
//        cout<<arp[i][j]<<" ";
        if (arp[i][j]==0){cout<<".";continue;}
        q=1;
        while (dwn[q+1]<arp[i][j])++q;
        cout<<char(q+'a'-1);
    }
    cout<<endl;
}

cin.get();cin.get();
return 0;}
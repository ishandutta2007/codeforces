/*
Sealing light
Nothing to see
Like a miracle life
Starts with the pain
Forever this will be

Close my eyes
Thunders won't cease
Crawling down to the edge
I break down and weep
Tears on the river deep
Oh! Back to the sea

Shout loud
Moving ahead
Ride the horses of justice
Virtues of men, yawns!

Down and out
Losing my head
Like a dream you're returning
Back from the dead-awake!
Shadows will fade some day
All the heroes go down
Shed their blood on the land
Dreaming somehow
The divine will now stand
Heroes go down
With their hearts in their hands
Building their castles on the sand

Haunted by the heavy clouds
Thunder scaring away
Howling like a mountain wolf
Warriors are leading the way
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define move asdfasdf

using namespace std;

string st;
int board[200][200],move[200][200];
int beaten[200][200];
int n;
int er;

bool valid(int a,int b)
{
    return (a>=1&&a<=n&&b>=1&&b<=n);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=st.size();j++)
    {
        if (st[j-1]=='o')
            board[i][j]=1;
        if (st[j-1]=='x')
            board[i][j]=2;
    }
}

for (int i=1;i<=n*2;i++)
 for (int j=1;j<=n*2;j++)
  move[i][j]=1;
  
for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)  
        for (int q=1;q<=n;q++)
            for (int w=1;w<=n;w++)
            if (board[i][j]==1&&board[q][w]==0)
            {   
                move[q-i+n][w-j+n]=0;
            }

for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        beaten[i][j]=0;
        
for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        if(board[i][j]==1)
        for (int di=-n+1;di<n;di++)
            for (int dj=-n+1;dj<n;dj++)
            if (valid(i+di,j+dj))
            {
                if (move[di+n][dj+n])
                    beaten[i+di][j+dj]=1;
            }
            
int er=0;
for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
     if (board[i][j]==2&&beaten[i][j]==0)
        er=1;

//er=0;

if (er)
cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    for (int i=1;i<=n*2-1;i++){
        for (int j=1;j<=n*2-1;j++)
        {
            if (i==n&&j==n)
                cout<<"o";
            else if (move[i][j])cout<<"x";
            else cout<<".";
        }
        cout<<endl;}
}

cin.get();cin.get();
return 0;}
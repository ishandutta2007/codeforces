/*
She's got a smile that it seems to me
Reminds me of childhood memories
Where everything
Was as fresh as the bright blue sky
Now and then when I see her face
She takes me away to that
special place
And if I stared too long
I'd probably break down and cry

Sweet child o' mine
Sweet love of mine

She's got eyes of the bluest skies
As if they thought of rain
I hate to look into those eyes
And see an ounce of pain
Her hair reminds me
of a warm safe place
Where as a child I'd hide
And pray for the thunder
And the rain
To quietly pass me by

Sweet child o' mine
Sweet love of mine

Where do we go
Where do we go now
Where do we go
Sweet child o' mine
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define div iryiwrydsfhkljfbhvbS
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std; 

long arp[250000][5],ar[250000],n,end[250000][5];
long long div[250000][5];

void dfs(long v,long move)
{
  //   cout<<v<<" "<<move<<endl;
     
 arp[v][move]=1;
     
 long long q,t;
 
 t=ar[v];
 if (move==2)q=v+ar[v]; 
 else q=v-ar[v];
 
          if (q>n||q<=0)
          {
           end[v][move]=1;
           div[v][move]=ar[v];
           return;                 
          }   
          else if (q==1)
          {
           return;
          }
          
          else
          {
            if (arp[q][5-move]==0)
           dfs(q,5-move);
           
           
            if (end[q][5-move]){end[v][move]=1;div[v][move]=div[q][5-move]+t;}
            else
            {return;}
            }
     
}

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=2;i<=n;i++)
cin>>ar[i];

dfs(4,3);

for (int i=2;i<=n;i++){
if (arp[i][2]==0)
{
                 dfs(i,2);
}
if (arp[i][3]==0)
dfs(i,3);
}

for (int i=2;i<=n;i++)
{
    if (end[i][3]==0)
    cout<<-1<<endl;
    else cout<<div[i][3]+i-1<<endl;
}

/*for (int i=1;i<=n;i++)
cout<<end[i][2]<<" "<<div[i][2]<<"   "<<end[i][3]<<" "<<div[i][3]<<endl;
*/

cin.get();cin.get();
return 0;}
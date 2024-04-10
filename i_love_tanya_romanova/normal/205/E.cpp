/*
Live by the sword and help to contain
The helpless minds of you all
Die by my hand in pools of blood
Clutch yourself as you fall
Mindless tyranny, forgotten victims
Children slaughtered in vain
Raping the maids, in which they serve
Only the words of the Lord

Die by the sword
Die by the sword

Satan watches all of us
Smiles as some do his bidding
Try to escape the grasp of my hand
And your life will no longer exist
Hear our cry, save us from
The Hell in which we live
We turn our heads toward the sky
And listen for the steel

Die by the sword
Die by the sword

Watch as flowers decay
On (the) cryptic life that died
The wisdom of the wizards
Is only a neurtured lie
Black knights of Hell's domain
Walk upon the dead
Satanas sits upon
The blood on which he feeds

Die by the sword
Die by the sword
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
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

double answ;
long long n,s1[300000][40];
string st1,st2;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st1;
cin>>st2;

for (long long i=1;i<=n;i++)
{
    for (int j='A'-'A';j<='Z'-'A';j++){
    s1[i][j]=s1[i-1][j];
    if (st2[i-1]-'A'==j)s1[i][j]+=i;}
    
    answ+=(n-i+1)*s1[i][st1[i-1]-'A'];
}

//cout<<answ<<endl;

reverse(st1.begin(),st1.end());
reverse(st2.begin(),st2.end());

for (long long i=1;i<=n;i++)
{
    for (int j='A'-'A';j<='Z'-'A';j++){
    s1[i][j]=s1[i-1][j];}
    answ+=(n-i+1)*s1[i][st1[i-1]-'A'];
    for (int j='A'-'A';j<='Z'-'A';j++){
    s1[i][j]=s1[i-1][j];
    if (st2[i-1]-'A'==j)s1[i][j]+=i;}
}
//cout<<answ<<endl;
long long znam=0;
for (long long i=1;i<=n;i++)
znam+=(n-i+1)*(n-i+1);
cout<<fixed<<answ*1.0/znam<<endl;

cin.get();cin.get();
return 0;}
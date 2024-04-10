/*
I was born into a scene of angriness and greed, and dominance and persecution.
My mother was a queen, my dad I've never seen, I was never meant to be.
And now I spend my time looking all around,
For a man that's nowhere to be found.
Until I find him I'm never gonna stop searching,
I'm gonna find my man, gonna travel around.

[Chorus]
'Cos I'm a wrathchild, well I'm a wrathchild.
Yeah I'm a wrathchild. I'm coming to get you, oooh yeah.

Say it doesn't matter ain't nothin' gonna alter the course of my destination.
I know I've got to find some serious piece of mind, or I know I'll go crazy.
But now I spend my time looking all around,
For a man thats nowhere to be found.
Until I find him I'm never gonna stop searching,
I'm gonna find my man, gonna travel around.

[Chorus]
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000002013
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

 double sc,qpres,p;
long long n,k,taq,qtotal;
vector<long long> ans;
long long tad;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
qtotal=n;
for (int i=1;i<=n;i++)
{
    cin>>p;
    sc=-1.0*(tad)*(qtotal-tad-1)*p;
 //   cout<<sc<<" "<<tad<<" "<<qtotal<<endl;
    sc+=qpres;
  //cout<<i<<" "<<sc<<" "<<qtotal<<" "<<qpres<<" "<<tad<<endl;
    if (sc>=k-0.654)
    {
        tad++;
        qpres+=1.0*(tad-1)*p;          
    }
    else
    {
        qtotal--;
        ans.push_back(i);
    }
}

for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}
/*
Sing me a song, you're a singer
Do me a wrong, you're a bringer of evil
The Devil is never a maker
The less that you give, you're a taker
So it's on and on and on
...it's Heaven and Hell, oh well

The lover of life's not a sinner
The ending is just a beginner
The closer you get to the meaning
The sooner you'll know that you're dreaming
So it's on and on and on
Oh it's on and on and on
It goes on and on and on, Heaven and Hell
I can tell, fool, fool!

Well, if it seems to be real, it's illusion
For every moment of truth, there's confusion in life
Love can be seen as the answer
But nobody bleeds for the dancer
And it's on and on, on and on and on....

They say that life's a carousel
Spinning fast, you've got to ride it well
The world is full of Kings and Queens
Who blind your eyes then steal your dreams
...it's Heaven and Hell, oh well

And they'll tell you black is really white
The moon is just the sun at night
And when you walk in golden halls
You get to keep the gold that falls
It's Heaven and Hell

No no fool, fool!
You got to bleed for the dancer!
Fool, fool, look for the answer!
Fool, fool, fool!
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
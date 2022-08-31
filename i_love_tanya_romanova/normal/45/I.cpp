/*
Liberty or death, what we so proudly hail
Once you provoke her, rattling of her tail
Never begins it, never, but once engaged...
Never surrenders, showing the fangs of rage

Don't tread on me

So be it
Threaten no more
To secure peace is to prepare for war
So be it
Settle the score
Touch me again for the words that you'll hear evermore...

Don't tread on me

Love it or live it, she with the deadly bite
Quick is the blue tongue, forked as lighting strike
Shining with brightness, always on surveillance
The eyes, they never close, emblem of vigilance

Don't tread on me

So be it
Threaten no more
To secure peace is to prepare for war
So be it
Settle the score
Touch me again for the words that you'll hear evermore...

Don't tread on me

So be it
Threaten no more
To secure peace is to prepare for war

Liberty or death, what we so proudly hail
Once you provoke her, rattling on her tail

So be it
Threaten no more
To secure peace is to prepare for war
So be it
Settle the score
Touch me again for the words that you'll hear evermore...

Don't tread on me
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
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,q;
vector<long> v1,v2;
long hz;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
 
 cin>>n;
 for (int i=1;i<=n;i++)
 {
     cin>>q;
     if (q>0)v1.push_back(q);
     if (q<0)v2.push_back(q);
     if (q==0)hz++;
 }
 sort(v1.begin(),v1.end());
 sort(v2.begin(),v2.end());
 if (v2.size()%2==1&&(v1.size()+v2.size()>1||hz>0))
 v2.erase(v2.end()-1);
 
 for (int i=0;i<v2.size();i++)
 v1.push_back(v2[i]);
 if (v1.size()==0)v1.push_back(0);
// cout<<v1.size()<<endl;
 for (int i=0;i<v1.size();i++)
 {if (i)cout<<" ";cout<<v1[i];}
 cout<<endl;
cin.get();cin.get();
return 0;}
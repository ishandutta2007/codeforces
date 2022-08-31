/*
Making two possibilities a reality 
prediting the future of things we all know 
fighting off the diseased programming 
of centuries, centuries, centuries, centuries 
Science fails to recognise the single most 
potent element of human existence 
letting the reigns go to the unfolding 
is faith, faith, faith, faith 
Science has failed our world 
science has failed our mother earth 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Letting the reigns go to the unfolding 
is faith, faith, faith, faith 
letting the reigns go to the unfolding 
is faith, faith, faith, faith 
Science has failed our world 
Science has failed our mother earth 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Spirit-moves-through-all-things 
Science has failed our mother earth
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

vector<long> v1,v2,v3;
long n,z,q,hz;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
z=1;
for (int i=1;i<=n;i++)
{
    cin>>q;
    if (q==0)hz=1;
    if (q==0)v3.push_back(q);
    else if (q<0)
    {
     if (v1.size()==0)v1.push_back(q);
     else
     {
      v2.push_back(q);
      z=-z;
     }
    }
    else v2.push_back(q);
}
sort(v2.begin(),v2.end());
if (z==-1&&v2[0]<0)
{
 v3.push_back(v2[0]);
 v2.erase(v2.begin());
 z=1;                  
}
if (hz==0||z==-1||v1.size()==0||v2.size()==0||v3.size()==0)
cout<<-1<<endl;
else
{
    cout<<v1.size();
    for (int i=0;i<v1.size();i++)
    cout<<" "<<v1[i];
    cout<<endl;
    
    
    cout<<v2.size();
    for (int i=0;i<v2.size();i++)
    cout<<" "<<v2[i];
    cout<<endl;
    
    
    cout<<v3.size();
    for (int i=0;i<v3.size();i++)
    cout<<" "<<v3[i];
    cout<<endl;
}

cin.get();cin.get();
return 0;}
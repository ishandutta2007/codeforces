/*
I close my eyes, only for a moment, and the moment's gone
All my dreams, pass before my eyes, a curiosity
Dust in the wind, all they are is dust in the wind
Same old song, just a drop of water in an endless sea
All we do, crumbles to the ground, though we refuse to see

Dust in the wind, All we are is dust in the wind

Don't hang on, nothing lasts forever but the earth and sky
It slips away, all your money won't another minute buy

Dust in the wind, All we are is dust in the wind
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
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std; 

long long n,tp,q,s;
vector<long long> v;
long long add,p,dv[500000],upd[50000];

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
v.push_back(0);
for (int i=1;i<=n;i++)
{
    cin>>tp;
    if (tp==2)
    {
     cin>>q;
     v.push_back(q);
     s+=q;
    }
    
    if (tp==1)
    {
              cin>>q;
              cin>>add;
              s+=q*add;
            //  dv[q]+=add;
              upd[q]+=add;
    }
    
    if (tp==3)
    {
            p=v.size();
            dv[p-1]+=dv[p]+upd[p];
            q=v[v.size()-1];
            q+=dv[p];q+=upd[p];
            s-=q;
            dv[p]=upd[p]=0;
            v.pop_back();            
    }
    
    cout.precision(8);
    cout<<fixed<<s*1.0/v.size()<<endl;
}

cin.get();cin.get();
return 0;}
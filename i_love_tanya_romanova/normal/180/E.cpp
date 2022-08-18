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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh


#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

vector<long> v[200000];
long q,n,k,m,s,l,r,col,ans,bst;

int main(){
//freopen("mitm.in","r",stdin);
//freopen("mitm.out","w",stdout);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v[q].push_back(i);
}

for (col=1;col<=m;++col)
{
    if (v[col].size()==0)continue;
    l=0;
    s=0;
    
    r=0;
    bst=1;
    while (r<v[col].size()-1)
    {
          r++;
          s+=v[col][r]-v[col][r-1]-1;
          while (s>k)
          {++l;s-=v[col][l]-v[col][l-1]-1;}
          bst=max(bst,r-l+1);
          //cout<<col<<" "<<l<<"   "<<r<<" "<<s<<endl;
    }
    ans=max(ans,bst);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}
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

long n,s,mx,q;
int main(){
//freopen("arithm.in","r",stdin);
//freopen("arithm.out","w",stdout);
ios_base::sync_with_stdio(0);

mx=100000;
cin>>n;
for (int i=0;i<n;i++)
{
    cin>>q;
    s+=q;
    if (q%2>0&&q<mx)mx=q;
    
}
if (s%2)cout<<s<<endl;
else if (mx%2)cout<<s-mx<<endl;
else cout<<0<<endl;
cin.get();cin.get();
return 0;}
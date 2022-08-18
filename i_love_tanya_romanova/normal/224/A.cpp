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

double a,b,c,aa,bb,cc,s;

int main(){
//freopen("circle.in","r",stdin);
//freopen("circle.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>c;
aa=sqrt(a*b/c);
bb=sqrt(b*c/a);
cc=sqrt(a*c/b);
s=aa+bb+cc;
cout<<4*s<<endl;

cin.get();cin.get();
return 0;}
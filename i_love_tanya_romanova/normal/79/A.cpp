#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
long x,y;
bool mv()
{if ((x>1&&y>1)||(x>0&&y>11)||(y>21))return true;
 return false;
}

void dmvc()
{if (x>1&&y>1){x-=2;y-=2;return;}
 if (x>0&&y>11){x--;y-=12;return;}
 y-=22;return;
 }
void dmvh()
{
 if (y>21){y-=22; return;}
  if (y>11){y-=12;--x; return;}
  if (y>1){y-=2; x-=2; return;}
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>x>>y;
for (int i=1;i<=10000000;i++)
{if (i%2==1){if (mv())dmvc(); else {cout<<"Hanako"<<endl;return 0;}}
 else
 {if (mv())dmvh(); else {cout<<"Ciel"<<endl; return 0;}}}

cin.get();cin.get();
return 0;}
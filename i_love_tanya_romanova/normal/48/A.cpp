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
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
string st1,st2,st3;
bool over(string st1,string st2)
{if (st1[0]=='p'&&st2[0]=='r')return true;
 if (st1[0]=='s'&&st2[0]=='p')return true;
 if (st1[0]=='r'&&st2[0]=='s')return true;
 return false;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1;
cin>>st2;
cin>>st3;
if (over(st1,st2)&&st2==st3)cout<<"F"<<endl;
else if (over(st2,st3)&&st1==st3)cout<<"M"<<endl;
else if (over(st3,st1)&&st1==st2)cout<<"S"<<endl;
else cout<<"?"<<endl;
cin.get();cin.get();
return 0;}
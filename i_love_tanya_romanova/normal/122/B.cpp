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
#define bs 1000000007
using namespace std;
string st;
long a,b;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;

for (int i=0;i<st.size();i++)
{if (st[i]=='4')a++;if (st[i]=='7')b++;}

if (a+b==0)cout<<-1<<endl;
else if (a>=b)cout<<4<<endl;
else cout<<7<<endl;

 cin.get();cin.get();
return 0;}
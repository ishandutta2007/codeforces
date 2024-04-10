#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
string st;
long h,m;
void incr()
{m++;if (m==60){m=0;h++;}
if (h==24)h=0;}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;

h=st[0]*10-480;
h+=st[1]-48;
m=st[3]-48;
m=m*10+st[4]-48;
if (h>=12)h-=12;
cout.precision(4);
cout<<fixed<<1.0*(h*60+m)/2<<" "<<m*6<<endl;
cin.get();cin.get();
return 0;
}
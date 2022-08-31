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
string st,stt[100];
bool cmp(long a,long b)
{for (int i=0;i<=9;i++)if (st[a*10+i]!=stt[b][i])return false;
return true;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
for (int i=0;i<=9;i++)cin>>stt[i];
for (int i=0;i<8;i++)
for (int j=0;j<=9;j++)if (cmp(i,j))cout<<j;
cout<<endl;
cin.get();cin.get();
return 0;
}
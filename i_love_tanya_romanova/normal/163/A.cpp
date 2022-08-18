
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
#define eps 1e-7
#define M_PI 3.141592653589793

//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back

using namespace std;
string st1,st2;
long ans[6000][6000],answ;
int main(){
//freopen("C:/aver.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>st1;
cin>>st2;
ans[0][0]=0;
for (int i=0;i<st1.size();i++)
for (int j=0;j<st2.size();j++)
{
    if (st1[i]==st2[j]){if (j)ans[i][j]=ans[i][j-1];if (i&&j)ans[i][j]+=ans[i-1][j-1];ans[i][j]%=bs; ans[i][j]+=1;}
 else { if (j>0)ans[i][j]=ans[i][j-1];}
 ans[i][j]%=bs;
}

for (int i=0;i<st1.size();i++){
answ+=ans[i][st2.size()-1];answ%=bs;}

cout<<answ%bs<<endl;
cin.get();cin.get();
return 0;}
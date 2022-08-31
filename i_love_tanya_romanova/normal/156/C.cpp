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
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long ans[200][2700],s,tests;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>tests;
ans[0][0]=1;
for (int i=0;i<=100;i++)
for (int j=0;j<=2600;j++)
for (int q=1;q<=26;q++)
{ans[i+1][j+q]+=ans[i][j];
 ans[i+1][j+q]%=bs;}
 
getline(cin,st);

for (;tests;--tests)
{
getline(cin,st);
    s=0;
    for (int i=0;i<st.size();i++)
    s+=st[i]-'a'+1;
    cout<<ans[st.size()][s]-1<<endl;
}
cin.get();cin.get();
return 0;}
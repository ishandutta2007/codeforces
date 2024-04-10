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
//#define bs 1000000007
//#define szz 400
using namespace std;
string st;
long q,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
while (st.size()>1)
{if (st[st.size()-1]=='0')st.erase(st.begin()+st.size()-1);
else
{
    q=st.size()-1;
    while (st[q]=='1'&&q>=0)
    {st[q]='0';--q;}
    if (q>=0)st[q]='1';else st='1'+st;
}
ans++;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}
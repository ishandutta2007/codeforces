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
long q,ans;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
q=0;ans=0;
for (int i=0;i<st.size();i++)
{//cout<<q<<" "<<ans<<endl;
 if (q==0){q=1;ans++;}
 else if (st[i]!=st[i-1]||q==5){q=1;ans++;}
 else q++;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}
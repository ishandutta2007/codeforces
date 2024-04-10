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
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;cin>>st;
if (st.size()<4)cout<<st<<endl;
else {
     for (int i=0;i<st.size();i++)
     {if (i+1<st.size()&&i%2==0&&i>0)cout<<"-";cout<<st[i];
     }
     }
     cout<<endl;
cin.get();cin.get();
return 0;
}
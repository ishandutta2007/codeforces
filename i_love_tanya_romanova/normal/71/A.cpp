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
long tests;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>tests;
for (;tests;--tests)
{cin>>st;
if (st.size()<11)cout<<st<<endl;
else cout<<st[0]<<st.size()-2<<st[st.size()-1]<<endl;
}
cin.get();cin.get();
return 0;
}
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
vector <long> v[10];
long n,q;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)
{cin>>q;v[q%2].push_back(i+1);
}
for (int i=0;i<2;i++)
if (v[i].size()==1)cout<<v[i][0]<<endl;
cin.get();cin.get();
return 0;
}
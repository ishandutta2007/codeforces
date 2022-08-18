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
long n,q;
vector <long> v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;q=2;
while (n>1)
{while(n%q==0){v.push_back(n);n/=q;}
 ++q;
}
v.push_back(1);
for (int i=0;i<v.size();++i)
{cout<<v[i];if (i+1!=v.size())cout<<" ";else cout<<endl;}

cin.get();cin.get();
return 0;}
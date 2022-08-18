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

long n;

bool iss(long q)
{while (q)
{if (q%10!=4&&q%10!=7)return false;q/=10;}
return true;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=1000;i++)
if (n%i==0&&iss(i)){cout<<"YES"<<endl;return 0;}
cout<<"NO"<<endl;
cin.get();cin.get();
return 0;}
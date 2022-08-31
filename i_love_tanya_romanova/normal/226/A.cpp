//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#include <memory.h>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
const int MAXN = 120000; 

long long n,m,bs;

long long pw(long long a,long long b)
{
     if (b==0)return 1;
     if (b%2)return pw(a,b-1)*a%bs;
     return pw(a*a%bs,b/2)%bs;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
bs=m;
cout<<(pw(3,n)+m-1)%m<<endl;
cin.get();cin.get();
return 0;}
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-6 
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long long n,m,maxx,ans[12000000][2];


int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

ans[0][0]=1;
cin>>n;
for (int i=0;i<n;i++)
{
    ans[i+1][0]+=ans[i][1];
    ans[i+1][1]+=ans[i][0]*3;
    ans[i+1][1]+=ans[i][1]*2;
    ans[i+1][1]%=bs;
    ans[i+1][0]%=bs;
}

cout<<ans[n][0]<<endl;

cin.get();cin.get();
return 0;}
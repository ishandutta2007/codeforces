//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;  

long long dif,n,p1,p2,p3,t1,t2,a[10000],b[10000],r;

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>p1>>p2>>p3>>t1>>t2;

for (int i=1;i<=n;i++)
{
    cin>>a[i]>>b[i];
    r+=(b[i]-a[i])*p1;
    if (i>1)
    {
            dif=a[i]-b[i-1];
            if (dif<=t1)
            {
                        r+=dif*p1;
                        dif=0;
            }
            else {r+=t1*p1;dif-=t1;}
            
            if (dif<=t2)
            {
                        r+=dif*p2;
            dif=0;}
            else
            {r+=t2*p2;dif-=t2;}
            r+=dif*p3;
    }
}

cout<<r<<endl;

cin.get();cin.get();
return 0;}
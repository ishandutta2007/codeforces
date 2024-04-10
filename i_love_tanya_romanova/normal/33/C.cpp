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
//#define pb push_back
using namespace std;
long long pw,n,ar[200000],s[200000],bs[200000],q;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];s[i]=s[i-1]+ar[i];
}

bs[n+1]=0;

for (int i=n;i;i--)
{
    bs[i]=min(bs[i+1],s[n]-s[i-1]);
}
/*
for (int i=1;i<=n;i++)
cout<<bs[i]<<" ";
cout<<endl;*/
q=0;
for (int i=1;i<=n;i++)
{pw=min(pw,s[i]);q=min(q,2*pw+2*bs[i+1]);}

//cout<<q<<endl;
cout<<s[n]-q<<endl;
cin.get();cin.get();
return 0;}
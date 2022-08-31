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
string st;
long n,k,ar[200000],cp;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>k;
getline(cin,st);
getline(cin,st);
for (int i=1;i<=n;i++)ar[i]=st[i-1]-48;

for (int i=1;i<=n-2;i++)
{if (ar[i]==4&&ar[i+1]==7&&ar[i+2]==7&&i%2==1&&cp==0){cp=i;}
 if (ar[i]==4&&ar[i+1]==4&&ar[i+2]==7&&i%2==1&&cp==0)cp=i;
}

if (cp==0)
{for (int i=1;i<n;i++)
{if (ar[i]==4&&ar[i+1]==7&&k>0)
{--k;
 if (i%2==1){ar[i+1]=4;} else ar[i]=7;
}
}
}

else 
{for (int i=1;i<cp;i++)
{if (ar[i]==4&&ar[i+1]==7&&k>0)
{--k;
 if (i%2==1){ar[i+1]=4;} else ar[i]=7;
}
}

if (k>0)
{if ((k%2==1&&ar[cp+1]==7)||(k%2==0&&ar[cp+1]==4))ar[cp+1]=4; else ar[cp+1]=7;}

}

for (int i=1;i<=n;i++)cout<<ar[i];
cout<<endl;

 cin.get();cin.get();
return 0;
 }
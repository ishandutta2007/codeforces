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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh


#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

string st;
long n,v,k;
long calc[1000];

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("peacefulsets.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>k;
cin>>st;
n=st.size();
//v=n/k;
if (n%k)
{
        cout<<-1<<endl;
        return 0;
}

for (int i=0;i<st.size();i++)
calc[st[i]-'a'+1]++;

long fl=0;
for (int i=1;i<=26;i++)
if (calc[i]%k)
{
               cout<<-1<<endl;
               return 0;
}

for (int i=1;i<=k;i++)
for (int j=1;j<=26;j++)
for (int q=1;q<=calc[j]/k;q++)
cout<<char(j+'a'-1);
cout<<endl;
cin.get();cin.get();
return 0;}
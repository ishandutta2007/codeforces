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

long n,m,a[100000],ar[200][200],b[100000],calc[100000],fl;
vector<long> ans;

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("peacefulsets.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
m=n*n-n;
m/=2;

for (int i=1;i<m;i++)
{
    cin>>a[i]>>b[i];
    calc[a[i]]++;
    calc[b[i]]++;
    ar[a[i]][b[i]]=1;
    
}

for (int i=1;i<=n;i++)
if (calc[i]==n-2)
ans.push_back(i);

long fl=0;
for (int i=1;i<=n;i++)
if (i!=ans[i]&&i!=ans[1]&&ar[i][ans[0]]==1&&ar[i][ans[1]]==0)
fl=1;
if (fl)cout<<ans[1]<<" "<<ans[0]<<endl;
else cout<<ans[0]<<" "<<ans[1]<<endl;


cin.get();cin.get();
return 0;}
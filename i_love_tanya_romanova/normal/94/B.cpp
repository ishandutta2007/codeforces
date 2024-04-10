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
//#define bs 1000000007
//#define szz 400
using namespace std;
long n,m,ar[200][200],a,b,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>m;
for (int i=1;i<=m;i++){cin>>a>>b;ar[a][b]=1;ar[b][a]=1;}
for (int i=1;i<=5;i++)
for (int j=i+1;j<=5;j++)
for (int q=j+1;q<=5;q++)
if (ar[i][j]+ar[i][q]+ar[q][j]==0||ar[i][j]+ar[i][q]+ar[q][j]==3)ans++;
if (ans)cout<<"WIN"<<endl;
else cout<<"FAIL"<<endl;
cin.get();cin.get();
return 0;}
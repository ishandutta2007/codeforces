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
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
//#define SIZE 60
using namespace std;
long n,q,s[10],bst,bp;

int main(){
//freopen("elevator.in","r",stdin);
//freopen("elevator.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 s[i%3]+=q;   
}

bp=-1;
bst=-1;

for (int i=0;i<3;i++)
if (s[i]>bst)
{bst=s[i];bp=i;}

if (bp==0)cout<<"back"<<endl;
else if (bp==1)cout<<"chest"<<endl;
else cout<<"biceps"<<endl;

cin.get();cin.get();
return 0;}
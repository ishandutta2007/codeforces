#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long n,fl;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=100;i++)if (i*(i-1)/2==n)fl++;
if (fl)cout<<"YES"<<endl; else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;
}
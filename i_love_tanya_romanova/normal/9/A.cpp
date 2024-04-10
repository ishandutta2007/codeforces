#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
long n,m;
 int main(){
 //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);)answ=max(answ,ans[i]);
cin>>n>>m;
n=max(n,m);
if (n==1)cout<<"1/1"<<endl;
if (n==2)cout<<"5/6"<<endl;
if (n==3)cout<<"2/3"<<endl;
if (n==4)cout<<"1/2"<<endl;
if (n==5)cout<<"1/3"<<endl;
if (n==6)cout<<"1/6"<<endl;

cin.get();cin.get();cin.get();
return 0;
}
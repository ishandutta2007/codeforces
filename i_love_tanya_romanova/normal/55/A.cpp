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
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long n,arp[200000],q,s;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
arp[0]=1;
q=0;
for (int i=1;i<=100000;i++)
{q=q+i;q%=n;
 arp[q]=1;
}
for (int i=0;i<n;i++)
s+=arp[i];
if (s<n)cout<<"NO"<<endl; else cout<<"YES"<<endl;
cin.get();cin.get();
return 0;
}
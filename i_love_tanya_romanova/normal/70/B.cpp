#include <iostream>
#include <cmath>
#include <vector> 
#include <string> 
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
long long n,ans[100000],i,ll,l,tl,p,l1[100000],l2[100000],q,sz;
string st;
long long beg[100000],fin[100000];
int main(){
cin>>n;
getline(cin,st);
getline(cin,st);
l=-1;ll=st.length();beg[1]=-1;
fin[0]=-2;sz=1;
for (i=1;i<ll;i++)
{if (st[i]=='.'||st[i]=='?'||st[i]=='!'){fin[sz]=i;sz++;beg[sz]=i+1;}}

ans[0]=0;
for (i=1;i<=10000;i++)ans[i]=1000000;
//for (i=1;i<=sz;i++)cout<<beg[i]<<" "<<fin[i]<<endl;
sz--;
for (i=1;i<=sz;i++)
{for (q=0;q<i;q++)
if (fin[i]-fin[q]-1<=n&&ans[i]>ans[q]+1)ans[i]=ans[q]+1;}
if (ans[sz]>100000)cout<<"Impossible"<<endl; else cout<<ans[sz]<<endl;

cin.get();cin.get();
return 0;}
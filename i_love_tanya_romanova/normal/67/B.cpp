#include <math.h>
#include <iostream>
#include <algorithm>
//#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
long n,k,i,p,j,q,ans[2000],sz,ar[2000];
int main()
{//freopen("C://input.txt","r",stdin);freopen("C://output.txt","w",stdout);
cin>>n>>k;
for (i=1;i<=n;i++)cin>>ar[i];
for (i=n-k+1;i<=n;i++){sz++;ans[sz]=i;}
for (i=n-k;i>=1;--i)
{q=0;p=1;while (q<ar[i]){p++;if (ans[p-1]-i>=k)q++;}
for (j=sz+1;j>p;--j)ans[j]=ans[j-1];
ans[p]=i;sz++;
//for (j=1;j<=sz;j++)cout<<ans[j]<<" ";cout<<endl;
}
for (i=1;i<=n;i++)cout<<ans[i]<<" ";
cout<<endl;
cin.get();cin.get();
return 0;}
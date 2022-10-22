#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[300009];
set<int>num;
int main()
{

//ios::sync_with_stdio(0);
 scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)num.insert(i);
int l,r,x;
while(m--)
{
scanf("%d%d%d",&l,&r,&x);
set<int>::iterator it=num.lower_bound(l);

while(it!=num.end()&&(*it)<=r)
{

if((*it)==x){it++;continue;}
a[(*it)]=x;

num.erase(it);
it=num.lower_bound(l);
}




}
for(int i=1;i<=n;i++)printf("%d ",a[i]);
return 0;}
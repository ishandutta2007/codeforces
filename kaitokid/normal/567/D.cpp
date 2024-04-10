#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n,a,k,x,m;
set<int> st;
int how(int y)
{

return (y+1)/(a+1);

}
int main()
{
scanf("%d%d%d%d",&n,&k,&a,&m);
int l=how(n);
st.insert(0);
st.insert(n+1);
for(int i=1;i<=m;i++)
{

scanf("%d",&x);
st.insert(x);
set<int>::iterator it =st.find(x);
it--;
int y=*it;
it++;
it++;
int z=*it;
int was=how(z-y-1);
int is=how(z-x-1)+how(x-y-1);
l-=was-is;
if(l<k){printf("%d",i);return 0;}



}
printf("-1");
return 0;}
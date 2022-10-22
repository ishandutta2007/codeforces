#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int n,m,x;
stack <int> a;
int d[200009];
int num=1;
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<m;i++)
{
while(!a.empty()&&a.top()==num){a.pop();num++;}
cin>>d[i];
if(d[i]==num){num++;continue;}
if(!a.empty()&&d[i]>a.top()){cout<<-1;return 0;}
a.push(d[i]);



}
for(int i=0;i<m;i++)cout<<d[i]<<" ";
while(!a.empty())
{
for(int i=a.top()-1;i>=num;i--)
cout<<i<<" ";
num=a.top()+1;
a.pop();






}
for(int i=n;i>=num;i--)cout<<i<<" ";

return 0;}
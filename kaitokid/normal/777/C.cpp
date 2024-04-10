#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,d[100009];
vector <int> a[100009];
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++){cin>>x;a[j].push_back(x);}
for(int i=0;i<m;i++)
{
int fr=0,en=0;
while(en<n-1)
{
if(a[i][en]>a[i][en+1])
{
for(int j=fr;j<=en;j++)d[j]=max(d[j],en);
fr=en+1;


}
en++;

}
for(int j=fr;j<=en;j++)d[j]=max(d[j],en);
}
int k,y;
cin>>k;
while(k--)
{
cin>>x>>y;
x--;
y--;
if(d[x]<y)cout<<"No\n";
else cout<<"Yes\n";


}
return 0;}
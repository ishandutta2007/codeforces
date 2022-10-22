#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> v[10];
bool bl[10];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
string s;
for(int i=0;i<10;i++)
v[i].second=i;
for(int i=0;i<n;i++)
{
cin>>s;
bl[s[0]-'a']=true;
int r=1;
for(int i=s.size()-1;i>=0;i--)
{
v[s[i]-'a'].first+=r;
r*=10;
}


}
int ans=0;
sort(v,v+10);
bool d=false;
int k=1;
for(int i=9;i>=0;i--)
{
if(!d&&!bl[v[i].second]){d++;continue;}

ans+=k*v[i].first;
k++;

}
cout<<ans;
return 0;}
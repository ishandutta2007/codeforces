#include <bits/stdc++.h>
using namespace std ;
multiset<long long > a,b;
long long  x,ans;
int main(){
ios::sync_with_stdio(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;

if(!a.empty()&&x> *a.begin()){

if(!b.empty()&& *b.begin()<*a.begin()){ans+=x-*b.begin();a.insert(*b.begin());b.erase(b.begin());b.insert(x);continue;}


ans+=x-*a.begin();a.erase(a.begin());b.insert(x);continue;}
if(!b.empty()&&x> *b.begin())
{ans+=x-*b.begin();a.insert(*b.begin());b.erase(b.begin());b.insert(x);continue;}
a.insert(x);



}
cout<<ans;
 return 0;}
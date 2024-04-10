#include <bits/stdc++.h> 
using namespace std ;
set<int>a;
int n;
vector<int>v;
int x;

 int main(){
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)a.insert(i);

for(int i=2;i<=n;i++)
{cin>>x;
a.erase(x);
//if(a.empty()){v.push_back(1);continue;}
set<int>::iterator it=a.end();
it--;
int l=*it;

//cout<<i<<" "<<l;
v.push_back(i-(n-l));
}
cout<<"1 ";
for(int i=0;i<n-1;i++)
cout<<v[i]<<" ";
cout<<1;
return 0;}
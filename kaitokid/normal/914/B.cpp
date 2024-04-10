#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int a[100009];
set<int>st;
vector<int> v;
int main() {
ios::sync_with_stdio(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{

int x;
cin>>x;
a[x]++;
if(a[x]==1)v.push_back(x);
}

sort(v.begin(),v.end());
for(int i=v.size()-1;i>=0;i--)
{
if(a[v[i]]%2==1){cout<<"Conan";return 0;}



}
cout<<"Agasa";
 return 0; }
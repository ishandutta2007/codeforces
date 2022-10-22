#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
int a[200009][2];
vector<int> v;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
v.push_back(1);
int k=a[1][0];
int r=a[1][1];
if(a[r][0]==k||a[r][1]==k){v.push_back(r);v.push_back(k);}
else {v.push_back(k);v.push_back(r);}
int j=1;
while(a[v[j]][0]!=1&&a[v[j]][1]!=1)
{
if(a[v[j]][0]==v[j+1])v.push_back(a[v[j]][1]);
else v.push_back(a[v[j]][0]);
j++;
}
for(int i=0;i<n;i++)cout<<v[i]<<" ";
    return 0;
}
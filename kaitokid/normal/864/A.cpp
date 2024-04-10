#include <bits/stdc++.h>
using namespace std;
bool bl;
vector<int>num;
int a[200];
int x;
int main(){
int n;
cin>>n;
for(int i=0;i<n;i++)
{cin>>x;
if(a[x]==0)num.push_back(x);
a[x]++;

if(a[x]>n/2||num.size()>2)bl=true;
}

if(bl){cout<<"NO";return 0;}
cout<<"YES"<<endl;
cout<<num[0]<<" "<<num[1];

return 0;}
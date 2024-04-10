#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
int n, m, MinDiff=9999999;
vector <int> v(1002);

int main()
{
cin>>n>>m;
for(int i=0;i<m;++i)
cin>>v[i];

sort(v.begin(),v.end(), greater<int>());
for(int i=0;i<m-n+1;++i)
if(MinDiff>v[i]-v[i+n-1]) MinDiff=v[i]-v[i+n-1];

cout<<MinDiff;
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;
int n, v[102];

int main()
{

cin>>n;
for(int i=1;i<=n;i++)
cin>>v[i];
sort(v+1, v+n+1);
for(int i=1;i<=n;i++)
cout<<v[i]<<' ';

}
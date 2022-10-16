#include <bits/stdc++.h>

using namespace std;
int n, l, x;
vector <int> v;
int main()
{

cin>>n>>l;
for(int i=1;i<=n;i++)
    cin>>x, v.push_back(x);
    sort(v.begin(), v.end());

v.push_back(l+l-v.back());
v.push_back(-v.front());
sort(v.begin(), v.end());

double d=0;
for(int i=1;i<v.size();++i)
    if(d<v[i]-v[i-1])
        d=v[i]-v[i-1];
    printf("%.10f", double(d/2.));
    return 0;
}
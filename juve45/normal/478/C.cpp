#include <bits/stdc++.h>

using namespace std;

long long a, b, c;
vector <long long> v;

int main()
{
    cin>>a>>b>>c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sort(v.begin(), v.end());

    if(2*(v[0]+v[1]) < v[2]) cout<<v[0]+v[1];
    else cout << (a+b+c)/3LL;

    return 0;
}
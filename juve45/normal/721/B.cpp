#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int ans, k, pass, les, eq;
vector <int> v;
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)
{
    cin>>s;
    v.push_back(s.size());
}
cin>>s;
pass=s.size();
sort(v.begin(), v.end());
int ok=0;
for(int i=0;i<v.size();i++)
{
    if(v[i]<pass) les++;
    if(v[i]==pass) eq++;
}

int ans1=les+1+(les/k)*5;
int ans2=les+eq+((les+eq-1)/k)*5;

cout<<ans1<<" "<<ans2;
    return 0;
}
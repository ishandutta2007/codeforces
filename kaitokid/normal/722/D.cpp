#include <bits/stdc++.h>

using namespace std;
set<int> s;
int n;
vector<int>ans;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
int x;
for(int i=0;i<n;i++)
{
    cin>>x;
    s.insert(x);
}
set<int>::iterator it;
while(true)
{
    it=s.end();
    it--;
    int u=(*it);
    s.erase(it);
    int v=u/2;
    while(v>0&&s.find(v)!=s.end())
    v/=2;
    if(v>0){s.insert(v);continue;}

    cout<<u<<" ";
    for(it=s.begin();it!=s.end();it++)cout<<(*it)<<" ";
    return 0;


}
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map <int, int> is;
int n, m;
vector <int> sol;
int main()
{
cin>>n>>m;
int x;
for(int i=1;i<=n;i++)
    cin>>x, is[x]=1;

int j=1;
int ans=0;
while(ans<=m)
{
    if(is.find(j)==is.end())
        {
            ans+=j;
            sol.push_back(j);
        }
    j++;
}
sol.pop_back();
cout<<sol.size()<<'\n';
for(int i=0;i<sol.size();i++)
    cout<<sol[i]<<' ';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,a,b,root,r;
vector<int> v[100009];
bool bl[2];
void go(int x,int pr,int d)
{
    if(v[x].size()==1)
    {
        bl[d%2]=true;
        return;
    }
    int q=0;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u==pr)continue;
        if(v[u].size()==1)q++;
        go(u,x,d+1);
    }
r-=max(q-1,0);
    //cout<<x<<" "<<q<<" "<<r<<endl;

}
int main()
{ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<n;i++)
{
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
    if(v[a].size()>1)root=a;
    if(v[b].size()>1)root=b;
}
r=n-1;
go (root,0,0);
if(bl[0]&&bl[1])cout<<3<<" ";
else cout<<1<<" ";
cout<<r;
    return 0;
}
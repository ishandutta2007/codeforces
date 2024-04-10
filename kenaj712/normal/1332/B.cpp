#include<bits/stdc++.h>
using namespace std;
int dziel[15]={2,3,5,7,11,13,17,19,23,29,31};
vector<int> v[15];
int kolor[10005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        for(int y=0;y<11;y++)
        {
            if(b%dziel[y]==0)
            {
                v[y].push_back(x);
                break;
            }
        }
    }
    int licz=1;
    for(int x=0;x<11;x++)
    {
        if(v[x].size()>0)
        {
            for(auto y:v[x])
                kolor[y]=licz;
            licz++;
        }

        v[x].resize(0);
    }
    cout<<licz-1<<'\n';
    for(int x=0;x<a;x++)
        cout<<kolor[x]<<" ";
    cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
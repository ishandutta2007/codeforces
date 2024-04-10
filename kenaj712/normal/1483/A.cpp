#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
int licz[1000005];
int chosen[1000005];
void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        int c;
        cin>>c;
        for(int y=0;y<c;y++)
        {
            int d;
            cin>>d;
            v[x].push_back(d);
            if(c == 1)
            {
                licz[d]++;
                chosen[x] = d;
            }

        }
    }
    int pom = b/2;
    if(b%2)
        pom++;
    for(int x=0;x<b;x++)
        if(v[x].size() > 1)
        {
            for(auto y:v[x])
                if(licz[y] < pom)
                {
                    licz[y]++;
                    chosen[x] = y;
                    break;
                }
        }
    bool czy = true;
    for(int x=1;x<=a;x++)
        if(licz[x] > pom)
            czy = false;
    if(!czy)
        cout<<"NO\n";
    else
    {
        cout<<"YES"<<'\n';
        for(int x=0;x<b;x++)
            cout<<chosen[x]<<" ";
        cout<<'\n';
    }
    for(int x=0;x<b;x++)
    {
        v[x].resize(0);
        chosen[x] = 0;
    }
    for(int x=1;x<=a;x++)
        licz[x] = 0;
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
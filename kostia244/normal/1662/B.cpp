#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string t,o,r;
    cin>>t>>o>>r;
    int cnt[3][26]={};
    for(char c:t) cnt[0][c-'A']++;
    for(char c:o) cnt[1][c-'A']++;
    for(char c:r) cnt[2][c-'A']++;

    vector<int> pairs[3];
    vector<int> ones[3];
    for(int i=0;i<26;i++)
    {
        while(true)
        {
            int &x=cnt[0][i],&y=cnt[1][i],&z=cnt[2][i];
            if(x==0&&y==0||
               x==0&&z==0||
               y==0&&z==0)
                break;
            if(x<=y&&x<=z)
                pairs[0].push_back(i),y--,z--;
            else if(y<=x&&y<=z)
                pairs[1].push_back(i),x--,z--;
            else if(z<=x&&z<=y)
                pairs[2].push_back(i),x--,y--;
        }
        int &x=cnt[0][i],&y=cnt[1][i],&z=cnt[2][i];
        while(x--) ones[0].push_back(i);
        while(y--) ones[1].push_back(i);
        while(z--) ones[2].push_back(i);
    }
    vector<pair<int,int>> ans;

    while(!pairs[0].empty()&&!ones[0].empty())
        ans.push_back({pairs[0].back(),ones[0].back()}),
        pairs[0].pop_back(),ones[0].pop_back();
    while(!pairs[1].empty()&&!ones[1].empty())
        ans.push_back({pairs[1].back(),ones[1].back()}),
        pairs[1].pop_back(),ones[1].pop_back();
    while(!pairs[2].empty()&&!ones[2].empty())
        ans.push_back({pairs[2].back(),ones[2].back()}),
        pairs[2].pop_back(),ones[2].pop_back();

    while(!pairs[0].empty()&&!pairs[1].empty()&&!pairs[2].empty())
        ans.push_back({pairs[0].back(),pairs[1].back()}),
        ans.push_back({pairs[0].back(),pairs[2].back()}),
        pairs[0].pop_back(),pairs[1].pop_back(),pairs[2].pop_back();

    while(true)
    {
        auto&X=ones[0],&Y=ones[1],&Z=ones[2];
        int x=X.size(),y=Y.size(),z=Z.size();
        if(x==0&&y==0||
           x==0&&z==0||
           y==0&&z==0)
            break;
        if(x<=y&&x<=z)
            ans.push_back({Y.back(),Z.back()}),Y.pop_back(),Z.pop_back();
        else if(y<=x&&y<=z)
            ans.push_back({X.back(),Z.back()}),X.pop_back(),Z.pop_back();
        else if(z<=x&&z<=y)
            ans.push_back({X.back(),Y.back()}),X.pop_back(),Y.pop_back();

    }

    for(int x:pairs[0]) ans.push_back({x,x});
    for(int x:pairs[1]) ans.push_back({x,x});
    for(int x:pairs[2]) ans.push_back({x,x});
    for(int x:ones[0]) ans.push_back({x,x});
    for(int x:ones[1]) ans.push_back({x,x});
    for(int x:ones[2]) ans.push_back({x,x});

    cout<<ans.size()<<"\n";
    for(auto[x,y]:ans)
        cout<<char('A'+x)<<char('A'+y)<<"\n";
}
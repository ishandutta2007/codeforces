#include<bits/stdc++.h>
using namespace std;
int f(char a)
{
    if(a=='?')
        return 26;
    return int(a)-97;
}
vector<int> v1[30];
vector<int> v2[30];
vector<pair<int,int>> out;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int c;
    string a,b;
    cin>>c>>a>>b;
    for(int x=0;x<c;x++)
        v1[f(a[x])].push_back(x+1);
    for(int x=0;x<c;x++)
        v2[f(b[x])].push_back(x+1);
    for(int x=0;x<26;x++)
    {
        while(v1[x].empty()==false&&v2[x].empty()==false)
        {
            out.push_back(make_pair(v1[x].back(),v2[x].back()));
            v1[x].pop_back();
            v2[x].pop_back();
        }
    }
    while(v1[26].empty()==false)
    {
        for(int x=0;x<=26;x++)
        {
            if(v2[x].empty()==false)
            {
                out.push_back(make_pair(v1[26].back(),v2[x].back()));
                v1[26].pop_back();
                v2[x].pop_back();
                break;
            }
        }
    }
    while(v2[26].empty()==false)
    {
        for(int x=0;x<=26;x++)
        {
            if(v1[x].empty()==false)
            {
                out.push_back(make_pair(v1[x].back(),v2[26].back()));
                v1[x].pop_back();
                v2[26].pop_back();
                break;
            }
        }
    }
    cout<<out.size();
    cout<<'\n';
    for(auto x:out)
        cout<<x.first<<" "<<x.second<<'\n';
	return 0;
}
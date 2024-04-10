#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> skurwiel;
vector<pair<int,int>> out;
void wrzuc(int a,int offset)
{
    for(int x=1;x<a;x*=2)
        for(int y=offset;y<offset+a;y+=x*2)
            for(int z=y;z<y+x;z++)
                out.push_back(make_pair(z,z+x));

}
void merge_koniec()
{
    vector<int> v2,v3,v4;
    v2=v.back();
    v.pop_back();
    v3=v.back();
    v.pop_back();
    for(int x=0;x<v2.size();x++)
    {
        v4.push_back(v2[x]);
        v4.push_back(v3[x]);
        out.push_back(make_pair(v2[x],v3[x]));
    }
    v.push_back(v4);
}
void merge_start()
{
    vector<int> v2,v3;
    v2=v.back();
    v.pop_back();
    int pom=v2.size();
    while(pom--)
    {
        out.push_back(make_pair(v2.back(),skurwiel.back()));
        v3.push_back(v2.back());
        v3.push_back(skurwiel.back());
        v2.pop_back();
        skurwiel.pop_back();
    }
    v.push_back(v3);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int where=1;
    for(int x=1;x<=2000000;x*=2)
        if(a&x)
        {
            wrzuc(x,where);
            v.push_back({});
            for(int y=0;y<x;y++)
            {
                v.back().push_back(where);
                where++;
            }
        }
    skurwiel=v.back();
    v.pop_back();
    reverse(v.begin(),v.end());
    while(v.size()>1)
    {
        if(v[v.size()-1].size() == v[v.size()-2].size())
            merge_koniec();
        else
            merge_start();
    }
    cout<<out.size()<<'\n';
    for(auto x:out)
        cout<<x.first<<" "<<x.second<<'\n';
	return 0;
}
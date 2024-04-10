#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> out;
bool sorted()
{
    for(int x=0;x<v.size()-1;x++)
        if(v[x+1]<v[x])
            return false;
    return true;
}

void swapuj()
{
    vector<int> v2=out.back();
    vector<int> v4;
    vector<int> v3;
    while(!v2.empty())
    {
        while(v2.back()>0)
        {
            v4.push_back(v.back());
            v.pop_back();
            v2.back()--;
        }
        v2.pop_back();
        reverse(v4.begin(),v4.end());
        for(auto y:v4)
            v3.push_back(y);
        v4.resize(0);
    }
    v=v3;
}
void znajdz()
{
    for(int x=0;x<v.size();x++)
        for(int y=x+1;y<v.size();y++)
            if(v[x]==v[y]+1)
            {
                vector<int> v2;
                if(x!=0)
                    v2.push_back(x);
                int pom=x,ile=0;
                while(pom!=v.size()-1 && v[pom]+1==v[pom+1])
                {
                    pom++;
                    ile++;
                }
                v2.push_back(1+ile);
                v2.push_back(y-x-ile);
                if(v.size()-y-1!=0)
                    v2.push_back(v.size()-y-1);
                out.push_back(v2);
                swapuj();
                return;
            }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        v.push_back(b);
    }
    while(!sorted())
        znajdz();
    cout<<out.size()<<'\n';
    for(auto x:out)
    {
        cout<<x.size()<<" ";
        for(auto y:x)
            cout<<y<<" ";
        cout<<'\n';
    }
	return 0;
}
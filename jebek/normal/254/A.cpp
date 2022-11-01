#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;
typedef pair<ll,ll> pii;

long long n;
ll a;
vector<pii>v;
map<ll,int>m;

int main()
{
    fin>>n;
    for(int i=1;i<=2*n;i++)
    {
        fin>>a;
        if(m[a]==0)
            m[a]=i;
        else
        {
            v.push_back(pii(m[a],i));
            m[a]=0;
        }
    }
    if(v.size()<n)
    {
        fout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<v.size();i++)
            fout<<v[i].first<<" "<<v[i].second<<endl;
}
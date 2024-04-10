#include<bits/stdc++.h>
using namespace std;
long long lewo[300005];
long long prawo[300005];
long long ok;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    string b;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        v.push_back(-1);
        for(int y=0;y<b.size();y++)
        {
            if(b[y]=='(')
                v.push_back(0);
            else
                v.push_back(1);
            while(v[v.size()-1]==1&&v[v.size()-2]==0)
            {
                v.pop_back();
                v.pop_back();
            }
        }
        //for(int y=0;y<v.size();y++)
        //    cout<<v[y]<<" ";
        //cout<<'\n';
        if(v.size()==1)
            ok++;
        else if(v[1]==v[v.size()-1])
        {
            if(v[1]==0)
                lewo[v.size()-1]++;
            else
                prawo[v.size()-1]++;
        }
        v.resize(0);
    }
    long long licz=0;
    for(int x=1;x<=300001;x++)
        licz+=lewo[x]*prawo[x];
    //cout<<lewo[1]<<" "<<prawo[1]<<'\n';
    licz+=ok*ok;
    cout<<licz;

	return 0;
}
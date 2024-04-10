#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int licz[1000005];
bool block[1000005];
vector<int> v;
vector<int> out;
int suma=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    out.push_back(0);
    for(int x=1;x<=a;x++)
    {
        cin>>b;
        if(block[abs(b)]==true)
        {
            cout<<-1;
            return 0;
        }
        if(b>0)
        {
            if(licz[b]>0)
            {
                cout<<-1;
                return 0;
            }
            licz[b]++;
            v.push_back(b);
            suma++;
        }
        else
        {
            b*=(-1);
            if(licz[b]<1)
            {
                //cout<<x;
                cout<<-1;
                return 0;
            }
            licz[b]--;
            block[b]=true;
            suma--;
            if(suma==0)
            {
                out.push_back(x);
                for(auto y:v)
                    block[y]=false;
                v.resize(0);
            }
        }
    }
    if(suma==0)
    {
        cout<<out.size()-1<<'\n';
        for(int x=1;x<out.size();x++)
            cout<<out[x]-out[x-1]<<" ";
    }
    else
        cout<<-1;
	return 0;
}
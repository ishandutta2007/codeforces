#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    long long suma=0;
    for(int x=0;x<b;x++)
    {
        cin>>tab[x];
        suma+=tab[x];
        if(tab[x]+x>a)
        {
            cout<<-1;
            return 0;
        }
    }
    if(suma<a)
    {
        cout<<-1;
        return 0;
    }
        
    for(int x=0;x<b;x++)
        v.push_back(x+1);
    v.push_back(a+1);
    for(int x=v.size()-2;x>=0;x--)
    {
        if(v[x]+tab[x]>=v[x+1])
            break;
        while(v[x]+tab[x]<v[x+1])
            v[x]++;
    }
    v.pop_back();
    for(auto x:v)
        cout<<x<<" ";
	return 0;
}
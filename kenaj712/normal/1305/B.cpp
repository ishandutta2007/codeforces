#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    int pocz=0,kon=a.size()-1;
    while(pocz<kon)
    {
        while(pocz < a.size() && a[pocz]==')')
            pocz++;
        while(kon>=0 && a[kon]=='(')
            kon--;
        if(pocz<kon)
        {
            v.push_back(pocz+1);
            v.push_back(kon+1);
            pocz++;
            kon--;
        }
    }
    if(v.size()==0)
    {
        cout<<0;
        return 0;
    }
    cout<<1<<'\n'<<v.size()<<'\n';
    sort(v.begin(),v.end());
    for(auto x:v)
        cout<<x<<" ";
	return 0;
}
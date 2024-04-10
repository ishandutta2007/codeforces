#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s;
vector<int> v[2];
int a;
void ask(int x)
{
    cout<<"? "<<x<<'\n';
    cout.flush();
    for(int y=1;y<=a;y++)
    {
        int b;
        cin>>b;
        if(b == 1)
            s.insert(make_pair(min(x,y) , max(x,y)));
    }
}
int main()
{
	cin>>a;
	cout<<"? "<<1<<'\n';
    cout.flush();
    for(int y=1;y<=a;y++)
    {
        int b;
        cin>>b;
        if(b == 1)
            s.insert(make_pair(min(1,y) , max(1,y)));
        if(b != 0)
            v[b%2].push_back(y);
    }
    if(v[0].size() < v[1].size())
    {
        for(auto x:v[0])
            ask(x);
    }
    else
    {
        for(auto x:v[1])
            ask(x);
    }

    cout<<"!"<<'\n';
    for(auto x:s)
        cout<<x.first<<" "<<x.second<<'\n';
	return 0;
}
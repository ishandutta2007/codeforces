#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    for(int x=0;x<26;x++)
    {
        string pom="";
        for(int y=x;y<26;y++)
        {
            pom+=char(y+97);
            s.insert(pom);
        }
    }
    int a;
    string b;
    cin>>a;
    while(a--)
    {
        cin>>b;
        sort(b.begin(),b.end());
        if(s.find(b)!=s.end())
            cout<<"Yes";
        else
            cout<<"No";
        cout<<'\n';
    }
	return 0;
}
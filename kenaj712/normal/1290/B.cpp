#include<bits/stdc++.h>
using namespace std;
int pref[200005][30];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    for(int x=1;x<=a.size();x++)
    {
        for(int y=0;y<26;y++)
            pref[x][y]=pref[x-1][y];
        pref[x][a[x-1]-'a']++;
    }
    int t;
    cin>>t;
    int c,d;
    while(t--)
    {
        cin>>c>>d;
        if(c==d)
        {
            cout<<"Yes"<<'\n';
            continue;
        }
        if(a[c-1]!=a[d-1])
        {
            cout<<"Yes"<<'\n';
            continue;
        }
        int licz=0;
        for(int x=0;x<26;x++)
            if(pref[d][x]-pref[c-1][x]>0)
                licz++;
        if(licz>=3)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<'\n';
    }
	return 0;
}
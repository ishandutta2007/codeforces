#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        int a,c;
        cin>>a;
        while(a--)
        {
            cin>>c;
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        bool czy=false;
        for(int x=0;x<v.size()-1;x++)
            if(v[x+1]-v[x]==1)
                czy=true;
        if(czy==true)
            cout<<2;
        else
            cout<<1;
        cout<<'\n';
    }
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
vector<int> v;
void solve()
{
    int a,b;
    cin>>a>>b;
    int xd2=b;
    string d;
    cin>>d;
    int sum=0;
    int ile=0;
    bool xd=false;
    bool lose=true;
    for(auto x:d)
    {
        if(x=='W')
        {
            xd=true;
            if(lose && ile!=0)
                v.push_back(ile);
            if(lose==1)
                sum++;
            else
                sum+=2;
            lose=false;
            ile=0;
        }
        else
        {
            ile++;
            lose=true;
        }
    }
    if(d[0]=='L' && xd)
    {
        //cout<<"XD"
        ile+=*v.begin();
        v.erase(v.begin());
    }


    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while(!v.empty() && v.back()<=b)
    {
        sum+=v.back()*2+1;
        b-=v.back();
        v.pop_back();
    }
    if(!v.empty())
        sum+=b*2;
    else
        sum+=min(ile,b)*2;
    if(xd==true)
        cout<<sum<<'\n';
    else
        cout<<max(xd2*2-1,0)<<'\n';
    v.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
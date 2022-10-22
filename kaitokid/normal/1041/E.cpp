#include <bits/stdc++.h>

using namespace std;
int n,x,y;
int c[1009];
vector<int> v[1009];
set<int>st;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        if(max(x,y)!=n||min(x,y)==n){cout<<"NO";return 0;}
        c[min(x,y)]++;
    if(c[min(x,y)]==2)st.insert(min(x,y));
    }
    for(int i=1;i<n;i++)
    {
        if(c[i]!=0)
        {
            if(v[i].size()==c[i]-1)continue;
            cout<<"NO";
            return 0;
        }
        set<int>::iterator it=st.upper_bound(i);
        if(it==st.end()){cout<<"NO";return 0;}
        int x=(*it);
        v[x].push_back(i);
        if(v[x].size()==c[x]-1)st.erase(it);
    }
    cout<<"YES\n";
    for(int i=1;i<n;i++)
    {
        if(c[i]==0)continue;
        if(c[i]==1){cout<<n<<" "<<i<<endl;continue;}
        cout<<n<<" "<<v[i][0]<<endl;
        for(int j=1;j<c[i]-1;j++)cout<<v[i][j-1]<<" "<<v[i][j]<<endl;
        cout<<v[i][c[i]-2]<<" "<<i<<endl;
    }
    return 0;
}
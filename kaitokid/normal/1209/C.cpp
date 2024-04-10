#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int rrr,fff;
vector<pair<int,int> >st;
int t,n;
int ans[200009];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>t;
while(t--)
{char x;
bool bl=false;
    cin>>n;
    st.clear();
    for(int i=0;i<n;i++)
    {
        cin>>x;
        st.push_back(make_pair(int(x-'0'),i));
    }

    sort(st.begin(),st.end());

    int d=1;
    ans[st[0].second]=1;
    for(int i=0;i<n-1;i++)
    {if(d==2&&st[i+1].first==rrr&&st[i+1].second>fff)
    {ans[st[i+1].second]=1;st[i+1].second=st[i].second;continue;}
        if((st[i].second)>(st[i+1].second)){d++;rrr=st[i+1].first;fff=st[i].second;}
    if(d>2){bl=true;break;}
ans[st[i+1].second]=d;

}
if(bl){cout<<"-"<<endl;continue;}
for(int i=0;i<n;i++)cout<<ans[i];
cout<<endl;}
    return 0;
}
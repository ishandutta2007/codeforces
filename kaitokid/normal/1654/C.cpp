#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int last[40];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    multiset<ll>st,rr;
    ll sum=0;
    ll n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        st.insert(x);
        sum+=x;
    }
    if(n==1){cout<<"YES"<<endl;continue;}
    rr.insert(sum);
    bool ans=true;
    while(!st.empty())
    {
        if(rr.size()>st.size()){ans=false;break;}
        multiset<ll>::iterator it=rr.end();
        it--;
        ll p=*(it);
        rr.erase(it);
        if(st.find(p/2)!=st.end()){st.erase(st.find(p/2));}else rr.insert(p/2);
        p++;
        if(st.find(p/2)!=st.end()){st.erase(st.find(p/2));}else rr.insert(p/2);

    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
}
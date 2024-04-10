#include <bits/stdc++.h>

using namespace std;
pair<pair<int,int>,int>a[100009];
int ans[100009];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first.first;
        cin>>a[i].first.second;
        a[i].second=i;
    }
    sort(a,a+n);
    set<pair<int,int> >st;
    set<pair<int,int> >::iterator it1,it2,it3;
    for(int i=n-1;i>=0;i--)
    {
        int l=a[i].first.first,r=l+a[i].first.second,res=1;
        it1=st.lower_bound({l,0});
        it2=st.lower_bound({r,0});
        while(it1!=it2)
        {
            res+=(*it1).second;
            it3=it1;
            it1++;
            st.erase(it3);
        }

        ans[a[i].second]=res;
        st.insert({l,res});
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}
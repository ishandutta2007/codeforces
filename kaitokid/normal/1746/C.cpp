#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],ans[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        set<int>st;
        for(int i=1;i<=n;i++){cin>>a[i];st.insert(i);ans[i]=n;}
        for(int i=2;i<=n;i++)
        {
            if(a[i]>a[i-1])continue;
            int d=a[i-1]-a[i];
            set<int>::iterator it=st.lower_bound(d);
            ans[(*it)]=i;
            st.erase(it);
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;

    }
    return 0;
}
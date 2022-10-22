#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,bit[100009];
int a[100009];
void upd(int x,int v)
{
    while(x<=n)
    {
        bit[x]=min(bit[x],v);
        x+=(x&(-x));
    }
}
int cal(int x)
{
    int res=INT_MAX;
    while(x>0)
    {
        res=min(res,bit[x]);
        x-=(x&(-x));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int mn=INT_MAX;
        set<int>st;
        for(int i=1;i<=n;i++)
        {cin>>a[i];
        if(a[i]<mn){st.insert(a[i]);mn=a[i];}
        bit[i]=INT_MAX;}
        st.insert(-1);
        for(int i=1;i<=n;i++)upd(i,a[i]);
        for(int i=0;i<m;i++)
        {
            int x,d;
            cin>>x>>d;
            a[x]-=d;
            int r=cal(x-1);
            set<int>::iterator it=st.lower_bound(r);
            it--;
            while((*it)>a[x])
            {
                set<int>::iterator it2=it;
                it2--;
                st.erase(it);
                it=it2;
            }
            if(a[x]<r)st.insert(a[x]);
            cout<<st.size()-1<<" ";
            upd(x,a[x]);
        }
        cout<<endl;



    }
    return 0;

}
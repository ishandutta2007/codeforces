#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

const int nmax=1e5+100;
#define int long long

int n;
int a[nmax];
int pos[nmax];
int arr[nmax];
int t[4*nmax];

void upd(int v, int l, int r, int pos, int val)
{
    if (l==r)
        t[v]=val, arr[pos]=val;
    else
    {
        int m=(l+r)/2;
        if (pos<=m) upd(2*v, l, m, pos, val);
        else upd(2*v+1, m+1, r, pos, val);
        t[v]=max(t[2*v], t[2*v+1]);
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i], pos[a[i]]=i;
        for (int i=1; i<=4*n; i++)
            t[i]=0;
        for (int i=1; i<=n; i++)
            upd(1, 1, n, i, 1);
        set<int> st;
        for (int i=1; i<=n; i++)
            st.insert(i);
        bool good=true;
        for (int i=1; i<=n; i++)
        {
//            for (int i=1; i<=n; i++)
//                cout<<arr[i]<<" ";
//        cout<<"\n";
            int mx=t[1];
            int m_x=arr[pos[i]];
            if (m_x<mx)
            {
                good=false;
                break;
            }
            auto it=st.upper_bound(pos[i]);
            if (it!=st.end())
                upd(1, 1, n, *it, m_x+arr[*it]);
            upd(1, 1, n, pos[i], 0);
            st.erase(pos[i]);
        }
        if (good)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
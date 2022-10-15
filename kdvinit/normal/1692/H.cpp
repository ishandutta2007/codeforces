/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    set<int> st;
    map<int, vector<int>> pos;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
        pos[a[i]].push_back(i);
    }

    int amx = 1;
    int an = a[1];
    int al = 1;
    int ar = 1;


    for(int x: st)
    {
        int tmx=-1;
        int tl=-1, tr=-1;

        int sum=0;
        int lst=-(n+100);
        int l2=lst;

        for(int y: pos[x])
        {
            int dif = y-l2-1;

            sum-=dif;
            sum++;

            if(sum<=0)
            {
                sum=1;
                lst=y;
            }

            if(sum>tmx)
            {
                tmx=sum;
                tl=lst;
                tr=y;
            }

            l2=y;
        }

        if(tmx>amx)
        {
            amx=tmx;
            an=x;
            al=tl;
            ar=tr;
        }
    }

    cout<<an<<" "<<al<<" "<<ar<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
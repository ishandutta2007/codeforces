#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

//typedef long long ll;
//#define int ll

vector<int> v;
multiset<int> st;

int mex()
{
    for (int i=0; ;i++)
        if (!st.count(i))
            return i;
}

vector<int> ans;
void upd(int i)
{
    ans.pb(i);
    int r=v[i];
    v[i]=mex();
    st.erase(st.find(r));
    st.insert(v[i]);

//    cout<<i<<"\n";
//    for (int i:v)
//        cout<<i<<" ";
//    cout<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n;
        cin>>n;
        v.resize(n);
        st.clear();
        ans.clear();
        for (int i=0; i<n; i++)
            cin>>v[i], st.insert(v[i]);

        set<int> unused;
        for (int i=0; i<n; i++)
            unused.insert(i);
        vector<int> used(n, false);
        for (int i=0; i<n; i++)
        {
            int k=mex();
            if ((k<n) and (!used[k]))
            {
                upd(k), used[k]=true;
                continue;
            }
            vector<int> cnt(k);
            for (int i=0; i<n; i++)
                if (v[i]<k)
                    cnt[v[i]]++;

            int mn=-1;
            for (int i=0; i<k; i++)
                if (!used[i])
                    if ((mn==-1) or (used[i]<used[mn]))
                        mn=i;
            for (int i=0; i<n; i++)
                if (v[i]==mn)
                    upd(i);
            upd(mn);
            used[mn]=true;
        }


//        vector<int> used(n, false);
//        for (int c=0; c<n; c++)
//        {
//            bool ok=false;
//            for (int i=0; i<n; i++)
//                if (v[i]==c)
//                {
//                    if (ok)
//                        upd(i);
//                    else
//                        used[i]=true;
//                    ok=true;
//                }
//            if (!ok)
//                for (int i=0; i<n; i++)
//                    if (!used[i])
//                        upd(i), used[i]=true;
//        }
//
//        int lt=n-1;
//        for (int i=0; i<n; i++)
//        {
//            int c=mex();
//            if (c > lt)
//                upd(lt), lt--;
//            else
//        }

        cout<<ans.size()<<"\n";
        for (int i:ans)
            cout<<i+1<<" ";
        cout<<"\n";
    }
}
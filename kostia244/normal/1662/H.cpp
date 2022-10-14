#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

bool check(int w, int h, int s)
{
    if (s > w) return false;
    int lt = w;
    lt %= s;
    if (lt > 1) return false;
    lt += h-1;
    lt %= s;
    if (lt > 1) return false;
    lt += w-1;
    lt %= s;
    if (lt > 1) return false;
    lt += h-2;
    lt %= s;
    if (lt > 0) return false;
    return true;
}
void try_(int w, int h, int s, vector<int>& v)
{
    if (check(w, h, s) || check(h, w, s))
        v.pb(s);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int w, h;
        cin>>w>>h;

        /// w-2, h

        vector<int> st = {1};
        if ((w*h - (w-2)*(h-2))%2==0)
            st.pb(2);
        /// w::, w-1::, w-2::, h::, h-1::, h-2::
        for (int i=1; i*i<max(w, h); i++)
        {
            if (w%i==0)
            {
                try_(w, h, i, st);
                try_(w, h, w/i, st);
            }
            if ((w-1)%i==0)
            {
                try_(w, h, i, st);
                try_(w, h, (w-1)/i, st);
            }
            if ((w-2)%i==0)
            {
                try_(w, h, i, st);
                try_(w, h, (w-2)/i, st);
            }
            swap(w, h);
            if (w%i==0)
            {
                try_(w, h, i, st);
                try_(w, h, w/i, st);
            }
            if ((w-1)%i==0)
            {
                try_(w, h, i, st);
                try_(w, h, (w-1)/i, st);
            }
            if ((w-2)%i==0)
            {
                try_(w, h, i, st);
                try_(w, h, (w-2)/i, st);
            }
            swap(w, h);
        }

        sort(st.begin(), st.end());
        vector<int> ans;
        for (int i=0; i<st.size(); i++)
            if (i==0 || st[i-1]!=st[i])
                ans.pb(st[i]);
        cout<<ans.size();
        for (int i : ans)
            cout<<" "<<i;
        cout<<"\n";
    }

}
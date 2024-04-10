/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    set<string> cur_st;

    for(int i=0; i<n; i++)
    {
        string tmp;
        for(int j=0; j<=2 && i+j<n; j++)
        {
            tmp+=s[i+j];
            cur_st.insert(tmp);
        }
    }

    int lst = 1;
    for(int len=1; 1; len++)
    {
        lst*=26;
        for(int i=0; i<lst; i++)
        {
            string cur;
            int x = i;
            for(int j=1; j<=len; j++)
            {
                char y = 'a'+(x%26);
                cur+=y;
                x/=26;
            }
            reverse(cur.begin(), cur.end());
            if(cur_st.count(cur)==0) { cout<<cur<<endl; return; }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
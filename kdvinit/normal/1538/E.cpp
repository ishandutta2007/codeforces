/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int haha_pos(string pre, string suf)
{

}

int calculate_haha(string s)
{
    int tmp=0;
    int m =s.size();
    for(int i=0; i+3<m; i++)
    {
        if(s.substr(i, 4)=="haha") tmp++;
    }
    return tmp;
}

void solve()
{
    int n;
    cin>>n;

    string eql = "=";

    int cntr=0;
    map<string, int> ind;

    int cnt_haha[n+1]={0};
    string pre[n+1];
    string suf[n+1];
    string haha = "haha";

    int lst_ind;
    for(int i=1; i<=n; i++)
    {
        string var;
        cin>>var;

        if(ind[var]==0) ind[var] = ++cntr;
        if(i==n) lst_ind = ind[var];

        string op;
        cin>>op;

        if(op==eql)
        {
            string a, b, add;
            cin>>a>>add>>b;

            int i1 = ind[var];
            int i2 = ind[a];
            int i3 = ind[b];

            string tmp = suf[i2]+pre[i3];
            cnt_haha[i1] = cnt_haha[i2] + cnt_haha[i3] + calculate_haha(tmp);

            pre[i1] = pre[i2];
            suf[i1] = suf[i3];

            int p1 = pre[i1].size();
            int s1 = suf[i1].size();

            if(p1<3)
            {
                pre[i1]+=pre[i3];
                int m = pre[i1].size();
                if(m>3) pre[i1] = pre[i1].substr(0, 3);
            }

            if(s1<3)
            {
                suf[i1]+=suf[i2];
                int m = suf[i1].size();
                if(m>3) suf[i1] = suf[i1].substr(m-3, 3);
            }

            //Str[i1] = Str[i2]+Str[i3];
        }
        else
        {
            string s;
            cin>>s;

            int i1 = ind[var];

            int m = s.size();
            cnt_haha[i1] = calculate_haha(s);

            int mn = min(m, (int)3);
            pre[i1] = s.substr(0, mn);
            suf[i1] = s.substr(m-mn, mn);

            //cout<<"Assignment "<<s<<" "<<cnt_haha[i1]<<" "<<pre[i1]<<" "<<suf[i1]<<endl;
        }
    }

    int ans = cnt_haha[lst_ind];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
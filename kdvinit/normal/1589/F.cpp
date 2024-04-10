/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int pos[11][200][2];
int cnt[11][200];
vector<char> sigma;

string mem[200][1050];
const string nahi = "?";
const string mpt = "";

string maxx(string a, string b)
{
    if(a.size()>b.size()) return a;
    else return b;
}

int tst=0;

string dp(char c, int bm)
{
    int tm = bm;
    if(mem[c][bm]!=nahi) return mem[c][bm];

    int ind[n+1];
    for(int i=1; i<=n; i++) { ind[i]=(tm%2); tm/=2; }

    int cur[n+1];
    for(int i=1; i<=n; i++)
    {
        if(ind[i]+1>cnt[i][c]) return mem[c][bm]=mpt;
        cur[i]=pos[i][c][ind[i]];
    }

    string tmp="";
    for(char nc: sigma)
    {
        int nbm=0, ans_pos=1;
        for(int i=n; i>=1; i--)
        {
            int l=cnt[i][nc], ad=-1;
            for(int j=0; j<l; j++) if(pos[i][nc][j]>cur[i]) { ad=j; break; }
            if(ad==-1) { ans_pos=0; break; }
            nbm*=2; nbm+=ad;
        }
        if(ans_pos==0) continue;
        tmp=maxx(tmp, dp(nc, nbm));
    }

    return mem[c][bm]=c+tmp;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int m = s.size();
        for(int j=0; j<200; j++) cnt[i][j]=0;

        for(int j=0; j<m; j++)
        {
            int x = s[j];
            pos[i][x][cnt[i][x]++]=j;
        }
    }

    for(int i=1; i<200; i++) for(int j=0; j<1050; j++) mem[i][j]=nahi;

    string ans="";
    for(char i: sigma) ans = maxx(ans, dp(i, 0));
    cout<<ans.size()<<endl<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(char i='A'; i<='Z'; i++) sigma.push_back(i);
    for(char i='a'; i<='z'; i++) sigma.push_back(i);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
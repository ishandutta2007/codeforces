/*
K.D. Vinit  |,,|
Hello Stalker : )
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string final_ans;
int mx_inv;

int freq[4];
vector<int> pos[4];

char anot[4] = {'A', 'N', 'O', 'T'};
map<int, char> mp;

int cnt_inv(int ind1, int ind2)
{
    int j=0;
    int val = 0;
    for(int i=0; i<freq[ind1]; i++)
    {
        while(j!=freq[ind2] && pos[ind2][j]<pos[ind1][i]) j++;
        val+=j;
    }
    return val;
}

void check_cnt(vector<int>& per)
{
    int tmp=0;
    for(int i=0; i<4; i++) for(int j=i+1; j<4; j++) tmp+= cnt_inv(per[i], per[j]);

    if(tmp>mx_inv)
    {
        string b;
        for(auto x: per) for(int i=1; i<=freq[x]; i++) b+=anot[x];
        final_ans = b;
        mx_inv = tmp;
    }
}

void solve()
{
    string s;
    cin>>s;

    int n = s.size();
    if(n==1) { cout<<s<<endl; return; }
    for(int i=0; i<4; i++) { freq[i]=0; pos[i].clear(); }

    for(int i=0; i<n; i++)
    {
        int x = mp[s[i]];
        freq[x]++;
        pos[x].push_back(i);
    }

    mx_inv=-1;
    vector<int> per = {0, 1, 2, 3};
    do
    {
        check_cnt(per);
    }while(next_permutation(per.begin(), per.end()));

    cout<<final_ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int j=0; j<4; j++) mp[anot[j]]=j;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
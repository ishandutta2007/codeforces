#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7,maxm= 1e4+5;

int p[maxm];
int dp[maxm];

unordered_map<string,string> sot;

struct node
{
    node * next[26];
    int data;
    //int start;
    node(){
        for (int i=0;i<26;i++)
            next[i] = NULL;
        data = 0;
    }

};

typedef node * pnode;

void addstr(pnode in,string & s,int j)
{
    if (j==s.size()){
        in->data  = 1;
        return;
    }
    int need = s[j] - 'a';
   // int _nst = st+w;
    if ( in->next[ need ] != NULL)
        addstr(in->next[need],s,j+1);
    else
    {
        in->next[ need ] = new node();
        addstr(in->next[need],s,j+1);
    }
}

void dfs(pnode in)
{
//    cout<<"Letter "<<in->data<<" Number"<<in->start<<endl;
    for (int i=0;i<26;i++){
        if (in->next[i]!=NULL)
            {
                cout<<(char)(i+'a');
                dfs(in->next[i]);
            }
    }
    cout<<endl;
}

int main()
{
    //files1;
    pnode root = new node();
    int l1;
    scanf("%d",&l1);
    string s;
    cin >> s;
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        string ns;
        cin >> ns;
        string bad;
        bad.resize(ns.size());
        for (int  j=0;j<ns.size();j++)
            bad[j] = tolower(ns[j]);
       // cerr<<bad<<endl;

        sot[bad] = ns;
        addstr(root,bad,0);
    }

    //dfs(root);
    for (int i=0;i<maxm;i++)
        p [i] = -1;
    for (int pos = 0;pos < l1;pos++){
        pnode in = root;//->next[s[pos]-'a'];

        for (int last = pos;last >= 0 ;last--){
            in = in->next[s[last] - 'a'];
            if (in == NULL)
                break;
            if ( (dp[last-1] == 1 && in->data == 1) || (last == 0 && in->data == 1) ){
                dp[pos] = 1;
                p[pos] = last-1;
                break;
            }
        }

       // cerr<<dp[pos]<<' ';
    }

    int th = l1-1;
    vector<string> ans;
    string now;

    while (th != -1)
    {
        int prev = p[th];
        for (int i=th;i>prev;i--)
            now += s[i];
        ans.pb(now);
        now.clear();
        th = prev;
    }
   // printf("%d\n",ans.size());
    reverse(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++){
        cout<<sot[ans[i]]<<' ';
    }
    return 0;
}
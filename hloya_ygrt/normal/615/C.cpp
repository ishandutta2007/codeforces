#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

struct node
{
    node * next[26];
    char data;
    int start;
    node(){
        for (int i=0;i<26;i++)
            next[i] = NULL;
    }
    node(char in,int pos){
        data = in;
        start = pos;
        for (int i=0;i<26;i++)
            next[i] = NULL;
    }
};

typedef node * pnode;

void addstr(pnode in,string & s,int j,int st,int w) // j ,  
{
    if (j==s.size())
        return;
    int need = s[j] - 'a';
    int _nst = st+w;
    if ( in->next[ need ] != NULL)
        addstr(in->next[need],s,j+1,_nst,w);
    else
    {
        in->next[ need ] = new node(s[j],st);
        addstr(in->next[need],s,j+1,_nst,w);
    }
}
// for debug
void dfs(pnode in)
{
    cout<<"Letter "<<in->data<<" Number"<<in->start<<endl;
    for (int i=0;i<26;i++){
        if (in->next[i]!=NULL)
            {
                dfs(in->next[i]);
            }
    }
}
    vector<pair<int,int> > events;

pair<int,int> go(pnode in,string &s,int j,int h = 0)
{
        pair<int,int> ans = mp(h,in->start);

       // cerr << "IM ON LETTER "<<j<<endl;
       // cerr << "in have letter "<<in->data<<endl;
      //  cerr<<endl;
        if (j!=s.size())
        if (in->next[s[j]-'a']!=NULL){
            ans = go(in->next[s[j]-'a'],s,j+1,h+1);
          //  cout<<"MOVING FORWARD";
        }
        return ans;
}

int main()
{
    //files1;

    pnode proot = new node('#',-1);
    pnode sroot = new node('#',-1);
    string t;
    string s;
    cin>> s >> t;
    string pref, suf;
    suf = s;

    for (int i = 0;i<s.size();i++){
        if (!pref.empty())
            addstr(proot,pref,0,i-1,-1);
        if (!suf.empty())
            addstr(sroot,suf,0,i,1);
        pref.insert(pref.begin(),suf[0]);
        suf.erase(suf.begin());
    }
    addstr(proot,pref,0,s.size()-1,-1);

    int j = 0;
    //dfs(sroot);
  //  cerr<<endl;
    //dfs(proot);
  // pair<int,int> lcp1 = go(proot,t,j);

    while (j<t.size()){
        pair<int,int> lcp1 = go(proot,t,j);
        pair<int,int> lcp2 = go(sroot,t,j);
        if (lcp1.f==lcp2.f&&lcp1.f==0){
            printf("-1");
            return 0;
        }

        if (lcp1.f > lcp2.f){
            events.pb(mp(lcp1.f+lcp1.s-1,lcp1.s));
            j+=lcp1.f;
        } else
        {
            events.pb(mp(lcp2.s-lcp2.f+1,lcp2.s));
            j+=lcp2.f;
        }

    }
    printf("%d\n",events.size());
    for (int i=0;i<events.size();i++){
        printf("%d %d\n",events[i].f+1,events[i].s+1);
    }
    return 0;
}
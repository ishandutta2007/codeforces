#include <iostream>
#include <vector>
#include <cstring>

#define DMAX 101
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int n, r[DMAX], use[DMAX];
vector <pair<int, int> > p;
vector <int> v[DMAX];
bool asd;


void add_seg(int a, int b)
{
    p.pb(mp(a,b));
    for(int i=0; i<p.size(); i++)
    {
        if((p[i].x<a && a<p[i].y) || (p[i].x<b && b<p[i].y)) v[p.size()].pb(i+1);
        if((a<p[i].x && p[i].x<b) || (a<p[i].y && p[i].y<b)) v[i+1].pb(p.size());

    }
}

void valid(int a, int b)
{
    use[a]=1;
    for(int i=0; i<v[a].size(); i++)
        if(!use[v[a][i]] &&v[a][i]!=b)
    {
        use[v[a][i]]=1;
        valid(v[a][i], b);
        }
        else if(v[a][i]==b) {asd=true; return;}

    }

void read()
{
    int k, a, b;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>k>>a>>b;
        if(k==1) add_seg(a, b);
        if(k==2)
        {
            asd=false;
            memset(use, 0, sizeof(use));
            valid(a, b);
            if(asd==true) cout<<"YES\n";
            if(asd==false) cout<<"NO\n";
        }
    }

}

int main()
{
    read();
    return 0;

}
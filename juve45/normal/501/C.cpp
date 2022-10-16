#include <iostream>
#include <set>
#include <vector>

#define pb push_back

using namespace std;

const int DMAX=66000;
int n, a, b, nr[DMAX], x[DMAX], ans;

class cmp
{
public:
    bool operator()(const int& a, const int& b)
    {
        if(nr[a]!=nr[b])
        return nr[a]<nr[b];
        else
            return a<b;

    }
};

set <int, cmp> s;
vector <pair<int, int> >v;

void print_set()
{
    cout<<"\nSET:";
    for( set<int>::iterator i=s.begin(); i!=s.end(); ++i)
    cout<<*i<<" \n"[i==s.end()];
    cout<<'\n';
}

void solve()
{
    while(!s.empty())
    {
        int k=*s.begin();
        if(nr[k]==0)
            s.erase(s.begin());
        else{
        v.pb({x[k],k});
        ans++;
        nr[k]--;

        int kk=x[k];
        s.erase(s.begin());

        if(s.find(kk)!=s.end())
            s.erase(s.find(kk));//, cout<<" deleted:"<<kk;
        x[kk]=x[kk]^k;
        nr[kk]--;
        s.insert(kk);

        //print_set();

        }
    }
}

void print()
{
    cout<<ans<<'\n';
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<' '<<v[i].second<<'\n';
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        nr[i]=a;
        x[i]=b;
        s.insert(i);
        //print_set();
    }

//print_set();

    solve();

    print();

    return 0;
}
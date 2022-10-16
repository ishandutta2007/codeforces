#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define ll long long
#define lf long double

using namespace std;
priority_queue<int> v,used[100005];
set<int> s;
int required[100005],sum;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,a,b, beg=0;
    cin>>n;
    int ma=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if (a==0)
        v.push(0), beg++;
        used[a].push(b);
        ma=max(ma,a);
        sum+=b;
    }
    int total=n-beg;
    required[1]=sum;
    for (int j=1;j<=ma;j++)
        if (!used[j].empty())
            s.insert(j);
    int i=2, fin;
    while (!s.empty())
    {
        // cerr << sum << '\n';
        vector <int> to_erase;
        for (auto el:s)
        {
            total--;
            auto x=used[el].top();
            // cerr << el << ' ' << x << endl;
            used[el].pop();
            v.push(-x);
            sum-=x;
            if (used[el].empty()) {
                to_erase.push_back(el);
                // s.erase(el);
            }
        }

        for(auto e : to_erase) s.erase(e);
        while (total<i&&!v.empty())
        {
            total++;
            auto x=v.top();
            sum-=x;
            v.pop();
        }
        required[i]=sum;
        // cerr << "i si sum: "<< i << ' ' << sum << '\n';
        i++;
    } 
    fin = i - 1;
    int mi=required[1];
    // dbg_v(required, n + 1);
    for (int i=1;i<=fin;i++) 
        mi=min(mi,required[i]);
    cout<<mi;
    return 0;
}

//Long long output!!!
//Check constraints!!!
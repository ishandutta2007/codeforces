#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    int t=1;
    while (t--)
        solve();
    return 0;
}

#define int li

int n, k;
pair <pair <int, int>, int> goods[2000];
int b[2000];
int cc[2000];
vector <vector < int > > answer;
int sum=0;

void solve()
{  
    cin>>n>>k;
    int cnt=0;
    for (int i=0; i<n; i++)
    {
        cin>>goods[i].first.first>>goods[i].first.second, goods[i].second=i;
        b[i]=goods[i].first.first;
        cc[i]=goods[i].first.second;
        sum+=b[i];
        if (goods[i].first.second==2)
            goods[i].first.second=0;
        else
            cnt++;
    }
    sort (goods, goods+n);
    reverse (goods, goods+n);
    vector <int> now;
    for (int i=0; i<n; i++)
    {
        now.pb(goods[i].second);
        if ( goods[i].first.second==1 || i==n-1)
        {
            answer.pb(now);
            now.resize(0);
        }
    }
    
    int ans=0;
    if (answer.size()>=k)
    {
        vector <int> cur;
        for (int i=k; i<answer.size(); i++)
            for (int j=0; j<answer[i].size(); j++)
                answer[k-1].pb(answer[i][j]);
        
        for (int i=0; i<k; i++)
            if ( cc[answer[i][answer[i].size()-1]]==1 || cnt>=k)
                ans+=b[answer[i][answer[i].size()-1]];
        ans=2*sum-ans;
        cout<<ans/2;
        if (ans%2)
            cout<<".5";
        else
            cout<<".0";
        cout<<endl;
        for (int i=0; i<k; i++)
        {
            cout<<answer[i].size()<<' ';
            for (int j=0; j<answer[i].size(); j++)
                cout<<answer[i][j]+1<<' ';
            cout<<endl;
        }
        return;
    }
    
    for (int i=0; i<answer.size(); i++)
            if ( cc[answer[i][answer[i].size()-1]]==1 )
                ans+=b[answer[i][answer[i].size()-1]];
    
    while (answer.size()<k)
    {
        for (int i=0; i<answer.size(); i++)
            if(answer[i].size()>1)
            {
                vector <int> last;
                last.pb(answer[i][0]);
                answer.pb(last);
                answer[i].erase(answer[i].begin());
                break;
            }
    }
    
    ans=2*sum-ans;
    cout<<ans/2;
    if (ans%2)
        cout<<".5";
    else
        cout<<".0";
    cout<<endl;
    for (int i=0; i<k; i++)
    {
        cout<<answer[i].size()<<' ';
        for (int j=0; j<answer[i].size(); j++)
            cout<<answer[i][j]+1<<' ';
        cout<<endl;
    }
    
}
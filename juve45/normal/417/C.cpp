#include <iostream>
#include <vector>
#define DMAX 1001
#define pb push_back
using namespace std;
vector <int> v[DMAX];
int n, k, m=0;
inline bool valid(int i, int j)
{
if(i>j) return true;
if(v[i][0]<v[i][k-1]) if(j<v[i][0] || j>v[i][k-1]) return true;
if(v[i][0]<v[i][k-1])if(j>v[i][0] && j<v[i][k-1]) return true;
if(v[i][0]==v[i][k-1]) if(v[i][0]!=j) return true;
return false;
    }

void solve()
{
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=k;j++)
    {
        int h=i+j;
        if(h>n)h=h-n;
        if(valid(h, i)) v[i].pb(h), m++;
        else{
            cout<<-1;
            return;
            }
        }
    }
    cout<<m<<'\n';
    for(int i=1;i<=n;i++)
    for(int j=0;j<k;j++)
    cout<<i<<' '<<v[i][j]<<'\n';



    }


int main()
{
cin>>n>>k;
if(n==1) cout<<-1;
else
solve();
    return 0;
}
#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#define X first
#define Y second
#define MP make_pair

using namespace std;

const int MOD=1000000007;
typedef long long ll;
typedef pair<int,int> pii;
ll n,ans,k;
int MAX;
map<char,int>t;
char c[200000];
set<char>s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        t[c[i]]++;
        MAX=max(MAX,t[c[i]]);
    }
    for(int i=0;i<n;i++)
        if(MAX==t[c[i]])
            s.insert(c[i]);
    k=s.size();
    ans=1;
    for(int i=0;i<n;i++)
        ans=(ans*k)%MOD;
    cout<<ans<<endl;
}
#include <iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
ll a[30];
string s;
ll sum,ans;
map<pii,ll>m;

int main()
{
    for(int i=0;i<26;i++)
        cin>>a[i];
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        int k=int(s[i]-'a');
        sum+=a[k];
        m[pii(sum,s[i])]++;
        ans+=m[pii(sum,s[i+1])];
    }
    cout<<ans<<endl;
}
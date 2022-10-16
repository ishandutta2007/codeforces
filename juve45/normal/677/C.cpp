#include <iostream>
#define MOD 1000000007LL
using namespace std;

string s;
long long m[70], v[256],ans=1;
void pre()
{

    for(long long i=0;i<64;i++)
    for(long long j=0;j<64;j++)
    {
        m[i&j]++;
    }
for(long long i='0';i<='9';i++)
    v[i]=i-'0';
for(long long i='a';i<='z';i++)
    v[i]=i-'a'+36;
for(long long i='A';i<='Z';i++)
    v[i]=i-'A'+10;
        v['-']=62;
        v['_']=63;
}

int main()
{

pre();
cin>>s;

for(long long i=0;i<s.size();i++)
{
    ans*=m[v[s[i]]];
    //cout<<m[v[s[i]]]<<'\n';
    ans%=MOD;
}
cout<<ans<<'\n';
    return 0;
}
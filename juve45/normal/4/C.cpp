#include <iostream>
#include <vector>
#include <cstring>

#define HS1 66047
#define HS2 63307
#define B 31
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> pi;
vector <pi> v[HS1];
int n;
char s[40];

inline int hash1(char s[])
{
    int k=0, lg=strlen(s);
    for(int i=0; i<lg; ++i)
    {
        k=k*B+s[i]-'a'+1;
        if(k>=HS1)
            k=k%HS1;
    }
    return k;
}

inline int hash2(char s[])
{
    int k=0, lg=strlen(s);
    for(int i=0; i<lg; ++i)
    {
        k=k*B+s[i]-'a'+1 ;
        if(k>=HS2)
            k=k%HS2;
    }
    return k;
}

int search_hash(char s[])
{
    int h1=hash1(s);
    int h2=hash2(s);
    for(int i=0; i<v[h1].size(); ++i)
        if(v[h1][i].x==h2)
        {
            v[h1][i].y++;
            return v[h1][i].y-1;
        }
    return 0;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        int ss=search_hash(s);
        if(ss==0)
        {
            v[hash1(s)].pb(mp(hash2(s),1));
            cout<<"OK"<<'\n';
        }
        else
        {
            cout<<s<<ss<<'\n';
        }

    }

    return 0;
}
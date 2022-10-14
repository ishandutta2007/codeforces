#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const long long INF=1e18+10;
const int inf=1e9+10,dx[]= {0,0,1,-1,1,-1,1,-1},dy[]= {1,-1,0,0,1,1,-1,-1};
ll MOD=1e9+7;
double eps=1e-11;
//ld eps=1e-7,pi=acos(-1);

#define fi first
#define se second
#define be(x) x.begin(),x.end()
#define Last(x) (*(--x.end()))

int t;

string s;
int main()
{
ios::sync_with_stdio(0);

cin>>t;
while(t--)
{
    cin>>s;
    int x = 0,y = 0;
    vector<pair<int,int> >v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='L')--x;
        else if(s[i]=='R')++x;
        else if(s[i]=='U')++y;
        else --y;

        v.push_back({x,y});
    }

//    if(x != 0 && y != 0 )
//    {
//        cout<<"0 0\n";
//        continue;
//    }

    bool flag = 0;
    for(int j=0;j<s.size();j++)
    {
            int px = 0,py = 0;
            int ox = v[j].first,oy = v[j].second;

            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='L' && !(oy == py && ox == px - 1))--px;
                else if(s[i]=='R' && !(oy == py && ox == px + 1))++px;
                else if(s[i]=='U' && !(ox == px && oy == py + 1))++py;
                else if(s[i]=='D' && !(ox == px && oy == py - 1))--py;
            }

            if(px == 0 && py == 0)
            {
                cout<<ox<<" "<<oy<<"\n";
                flag = 1;
                break;
            }
    }

    if(flag == 0)
        cout<<"0 0\n";
}



    return 0;
}
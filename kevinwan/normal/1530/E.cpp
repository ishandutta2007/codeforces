#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;


int a[mn],p[mn];
bool u[mn];

void hailveshy(){
    string s;
    cin>>s;
    map<char,int>mp;
    for(char c:s)++mp[c];
    if(mp.size()==1){
        printf("%s\n",s.c_str());
        return;
    }
    for(auto p:mp){
        if(p.second==1){
            printf("%c",p.first);
            for(auto q:mp){
                if(q.first!=p.first){
                    for(int i=0;i<q.second;i++)
                        printf("%c",q.first);
                }
            }
            printf("\n");
            return;
        }
    }
    if(mp.begin()->second>=2&&mp.begin()->second*2<=s.size()+2){
        auto it=++mp.begin();
        string t;
        for(;it!=mp.end();++it)for(int i=0;i<it->second;++i)t.push_back(it->first);
        string ans;
        ans+= mp.begin()->first;
        ans+= mp.begin()->first;
        mp.begin()->second-=2;
        for(int i=0;i<mp.begin()->second;i++){
            ans.push_back(t[i]);
            ans.push_back(mp.begin()->first);
        }
        for(int i=mp.begin()->second;i<t.size();i++)ans.push_back(t[i]);
        printf("%s\n",ans.c_str());
        return;
    }
    string ans;
    ans+=mp.begin()->first;
    mp.begin()->second--;
    ans+=(++mp.begin())->first;
    (++mp.begin())->second--;
    if(mp.size()==2){
        for(int i=0;i<(++mp.begin())->second;i++)
            ans.push_back((++mp.begin())->first);
        for(int i=0;i<mp.begin()->second;i++)
            ans.push_back(mp.begin()->first);
        printf("%s\n",ans.c_str());
        return;
    }
    for(int i=0;i<mp.begin()->second;i++)
            ans.push_back(mp.begin()->first);
    ans+=(++(++mp.begin()))->first;
    (++(++mp.begin()))->second--;
    for(auto it=++mp.begin();it!=mp.end();++it)for(int i=0;i<it->second;++i)ans.push_back(it->first);
    printf("%s\n",ans.c_str());
        return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        hailveshy();
    }
}
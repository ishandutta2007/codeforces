#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
lll mul=5948735;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

struct ht{
    const static lll p=(ONE<<63)-25;
    lll x;
    ht operator+(const ht&ot){return (x+ot.x)%p;}
    ht operator-(const ht&ot){return (x-ot.x+p)%p;}
    ht operator*(const ht&ot){return x*ot.x%p;}
    ht(){x=0;}
    ht(lll x){this->x=x;}
};
ht p[mn],h[26][mn],th[26],v[26];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    p[0]=1;
    for(int i=1;i<mn;i++)p[i]=p[i-1]*mul;
    for(char c:t){
        for(int i=0;i<26;i++){
            if(c==i+'a')th[i]=th[i]*mul+'1';
            else th[i]=th[i]*mul+'0';
        }
    }
    for(int i=0;i<26;i++){
        if(s[0]==i+'a')h[i][0]='1';
        else h[i][0]='0';
    }
    for(int i=1;i<n;i++)for(int j=0;j<26;j++){
            if(s[i]==j+'a')h[j][i]=h[j][i-1]*mul+'1';
            else h[j][i]=h[j][i-1]*mul+'0';
        }
    vector<int>ans;
    for(int i=m-1;i<n;i++){
        for(int j=0;j<26;j++){
            v[j]=h[j][i]-(i-m>=0?(h[j][i-m]*p[m]):0);
        }
        vector<pair<lll,lll>>hh;
        for(int j=0;j<26;j++)if(v[j].x!=th[j].x)hh.push_back({min(v[j].x,th[j].x),max(v[j].x,th[j].x)});
        if(hh.size()%2==0){
            bool ded=0;
            sort(hh.begin(),hh.end());
            for(int i=0;i<hh.size();i+=2)if(hh[i]!=hh[i+1])ded=1;
            if(!ded)
            ans.push_back(i-m+2);
        }
    }
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}
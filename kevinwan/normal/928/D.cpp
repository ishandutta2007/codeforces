#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=998244353;
string s;
int ans,sav;
bool nu;
struct nd{
    map<char,nd*>c;
    int num,en;
};
nd*rt=new nd();
void add(nd*n,int ind){
    if(ind==s.size()){
        if(nu)n->en++;
        if(n->num)sav=0;
        return;
    }
    if(n->num+n->en!=1||n==rt||n->num!=1);
    else {
        sav++;
    }
    if(nu)n->num++;
    if(!n->c.count(s[ind]))n->c[s[ind]]=new nd();
    if(n->c.size()>1)sav=0;
    add(n->c[s[ind]],ind+1);

}
set<string>u;
int main(){
    cin>>noskipws;
    char c;
    while(cin>>c){
        //if(c=='?')break;
        if(c>='a'&&c<='z'){
            s.push_back(c);
        }
        else{
            ans++;
            if(!s.size())continue;
            nu=(u.find(s)==u.end());
            u.insert(s);
            sav=0;
            ans+=s.size();
            add(rt,0);
            ans-=max(0,sav-1);
            s.clear();
        }
    }
    if(s.size()) {
        nu=(u.find(s)==u.end());
        sav=0;
        ans+=s.size();
        add(rt,0);
        ans-=max(0,sav-1);
        s.clear();
    }
    printf("%d",ans);
}
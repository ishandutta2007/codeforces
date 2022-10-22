#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=50;
struct nd{
    map<char,int>c;
    int v,suf;
    nd():c{},v(0),suf(0){};
};
vector<nd>v={nd()};
int nnd(){
    v.push_back(nd());
    return v.size()-1;
}
void add(int x,string&s,int i){
    if(i==s.size()){
        v[x].v++;
        return;
    }
    if(!v[x].c.count(s[i]))v[x].c[s[i]]=nnd();
    add(v[x].c[s[i]],s,i+1);
}
void init(int r){
    queue<int>q;
    q.push(r);
    v[r].suf=r;
    while(q.size()){
        int x=q.front();
        v[x].v+=v[v[x].suf].v;
        q.pop();
        for(pii p:v[x].c)if(!v[p.second].suf){
            int y=p.second,c=p.first;
            q.push(y);
            if(x==r){
                v[y].suf=r;
                continue;
            }
            int t=v[x].suf;
            for(;t!=r&&!v[t].c.count(c);t=v[t].suf);
            v[y].suf=v[t].c.count(c)?v[t].c[c]:r;
        }
    }
}
int nxt(int x,char c){
    int t=x;
    for(;v[t].suf!=t&&!v[t].c.count(c);t=v[t].suf);
    return v[t].c.count(c)?v[t].c[c]:t;
}
struct AC{
    vector<string>v;
    int r;
};
vector<AC>ac,rac;
void idk(vector<AC>&ac){
    while(ac.size()>=2&&ac[ac.size()-2].v.size()==ac.back().v.size()){
        for(string&s:ac.back().v)ac[ac.size()-2].v.push_back(s);
        ac.pop_back();
    }
    ac.back().r=nnd();
    for(string&s:ac.back().v)add(ac.back().r,s,0);
    init(ac.back().r);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    while(n--){
        int a;
        string s;
        cin>>a>>s;
        if(a==1){
            ac.push_back(AC());
            ac.back().v.push_back(s);
            idk(ac);
        }
        else if(a==2){
            rac.push_back(AC());
            rac.back().v.push_back(s);
            idk(rac);
        }
        else{
            ll ans=0;
            for(AC&a:ac){
                int t=a.r;
                for(char c:s)t=nxt(t,c),ans+=v[t].v;
            }
            for(AC&a:rac){
                int t=a.r;
                for(char c:s)t=nxt(t,c),ans-=v[t].v;
            }
            printf("%lld\n",ans);
            fflush(stdout);
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll base=29LL;
ll pw[37];
struct name {
    int len;
    char s[37];
    ll hash;
    name(){}
    void create(void) {     
        scanf("%s",s);
        len=strlen(s);
        int i;
        hash=0LL;
        for (i=0;i<len;i=i+1) hash=hash+(s[i]-'a')*pw[i];
    }
    bool operator < (const name &x) const {
        if (len<x.len) return (true);
        if (len>x.len) return (false);
        return (hash<x.hash);
    }
    bool operator > (const name &x) const {
        return (x<*this);       
    }
    bool operator == (const name &x) const {
        if (*this<x) return (false);
        if (*this>x) return (false);
        return (true);
    }
    void print(void) const {
        printf("%s",s);
    }
};
struct event {
    name pl;
    int pre,aft;
    event(){}
    event(const name &_pl,const int &_pre,const int &_aft) {
        pl=_pl;pre=_pre,aft=_aft;
    }
};
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
map<name,int> scr;
vector<event> dia;
int n;
void process(void) {
    map<name,int>::iterator it;
    int i,s,m;
    name t;
    dia.clear();
    scr.clear();
    pw[0]=1LL;
    for (i=1;i<=35;i=i+1) pw[i]=pw[i-1]*base;
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1) {  
        t.create();
        scanf("%d",&s);     
        it=scr.find(t);
        if (it==scr.end()) {
            scr[t]=s;
            dia.push_back(event(t,0,s));
        }
        else {          
            (*it).second+=s;            
            dia.push_back(event(t,(*it).second-s,(*it).second));
        }
    }
    m=0;
    for (it=scr.begin();it!=scr.end();it++) maximize(m,(*it).second);
    for (i=0;i<dia.size();i=i+1) {
        t=dia[i].pl;
        if (scr[t]==m && dia[i].aft>=m) {
            t.print();
            return;
        }
    }
}
int main(void) {
    process();
    return 0;
}
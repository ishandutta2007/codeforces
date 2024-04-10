#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
typedef long long ll;
const ll base=29LL;
ll pw[37];
struct name {
    int len;
    ll hash;
    char s[37];
    name(){}
    void create(void) {
        scanf("%s",s);
        len=strlen(s);
        int i;
        hash=0LL;
        for (i=0;i<len;i=i+1)
            hash=hash+(s[i]-'a')*pw[i];
    }
    bool operator < (const name &x) const {
        if (len<x.len) return (true);
        if (len>x.len) return (false);
        return (hash<x.hash);
    }
};
map<name,int> data;
int n;
void process(void) {
    int i;
    pw[0]=1LL;
    for (i=1;i<=35;i=i+1) pw[i]=pw[i-1]*base;
    name t;
    map<name,int>::iterator it;
    data.clear();
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1) {
        t.create();
        it=data.find(t);
        if (it==data.end()) {
            printf("OK\n");
            data[t]=1;
        }
        else {
            printf("%s%d\n",t.s,(*it).second);
            (*it).second++;
        }
    }   
}
int main(void) {
    process();
    return 0;
}
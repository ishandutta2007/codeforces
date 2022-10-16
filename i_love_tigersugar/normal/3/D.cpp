#include<bits/stdc++.h>
#define MAX   50505
using namespace std;
const int INF=(int)1e9;
struct cost {
    int o,c,d,id;
    cost(){
        d=INF;
    }
    void input(const int &i) {
        scanf("%d",&o);
        scanf("%d",&c);
        d=o-c;
        id=i;
    }
    bool operator < (const cost &x) const {
        if (d<x.d) return (true);
        if (d>x.d) return (false);
        return (id<x.id);
    }
    bool operator > (const cost &x) const {
        return (x<*this);
    }
    bool operator == (const cost &x) const {
        if (x<*this) return (false);
        if (x>*this) return (false);
        return (true);
    }
};
char s[MAX];
cost a[MAX];
int b[MAX];
int n;
priority_queue <cost,vector<cost>,greater<cost> > q;
void init(void) {
    scanf("%s",&s[1]);
    n=strlen(&s[1]);
    int i;
    for (i=1;i<=n;i=i+1) 
        if (s[i]=='?') a[i].input(i);   
}
void process(void) {
    while (!q.empty()) q.pop();
    int i;
    long long res=0LL;
    cost t;
    b[0]=0;
    for (i=1;i<=n;i=i+1) {
        if (s[i]=='(') b[i]=b[i-1]+1;
        if (s[i]==')') b[i]=b[i-1]-1;
        if (s[i]=='?') {
            s[i]=')';
            b[i]=b[i-1]-1;
            q.push(a[i]);
            res=res+a[i].c;
        }
        if (b[i]<0) {
            if (q.empty()) {
                printf("-1");
                return;
            }
            t=q.top();q.pop();
            s[t.id]='(';
            b[i]=b[i]+2;
            res=res+t.d;
        }
    }
    if (b[n]!=0) {
        printf("-1");
        return;
    }
    printf("%I64d\n",res);
    printf("%s",&s[1]);
}
int main(void) {
    init();
    process();
    return 0;
}
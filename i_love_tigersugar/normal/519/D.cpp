#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORED(i,v) for (__typeof((v).rbegin()) i=(v).rbegin();i!=(v).rend();i++)
using namespace std;
int val[MAX];
long long s[MAX];
char a[MAX];
vector<int> pos[MAX];
map<long long,int> cnt;
void process(void) {
    FOR(i,'a','z') scanf("%d",&val[i]);
    scanf("%s",a+1);
    FOR(i,1,strlen(a+1)) s[i]=s[i-1]+val[a[i]];
    FOR(i,1,strlen(a+1)) pos[a[i]].push_back(i);
    long long res=0;
    FOR(i,'a','z') if (!pos[i].empty()) {
        cnt.clear();
        FORED(it,pos[i]) {
            res+=cnt[s[*it]];
            cnt[s[*it-1]]++;
        }
    }
    cout<<res<<endl;
}
int main(void) {
    process();
    return 0;
}
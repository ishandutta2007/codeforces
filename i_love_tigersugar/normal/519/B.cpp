#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> a,b,c;
int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int removed(const vector<int> &a,const vector<int> &b) {
    map<int,int> cnt;
    FORE(it,a) cnt[*it]++;
    FORE(it,b) cnt[*it]--;
    FORE(it,cnt) if (it->second>0) return (it->first);
}
int main(void) {
    int n=nextInt();
    REP(love,n) a.push_back(nextInt());
    REP(love,n-1) b.push_back(nextInt());
    REP(love,n-2) c.push_back(nextInt());
    printf("%d\n",removed(a,b));
    printf("%d\n",removed(b,c));
    return 0;
}
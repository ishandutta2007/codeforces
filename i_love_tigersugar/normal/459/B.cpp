#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
map<int,int> mp;
int main(void) {
    int n;
    scanf("%d",&n);
    REP(zz,n) {
        int t;
        scanf("%d",&t);
        mp[t]++;
    }
    if (mp.size()==1) {
        cout<<"0 "<<(1LL*n*(n-1)/2);
        return 0;
    }
    __typeof(mp.begin()) ft=mp.begin();
    __typeof(mp.begin()) lt=mp.end(); lt--;
    cout<<(lt->fi-ft->fi)<<" "<<(1LL*ft->se*lt->se);
    return 0;
}
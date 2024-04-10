#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string player[]={"Daenerys","Stannis"};
int winner(int cnt[],int k) {
    if (k==cnt[0]+cnt[1]) return (cnt[1]%2);
    int lastMove=(cnt[0]+cnt[1]-k)%2==0?0:1;
    int other=lastMove^1;
    bool win[2];
    REP(i,2) win[i]=(k*i)%2==other;
    int numMove[2];
    numMove[0]=(cnt[0]+cnt[1]-k-1)/2;
    numMove[1]=cnt[0]+cnt[1]-k-1-numMove[0];
    REP(i,2) if (cnt[i]>k && win[i])
        if (cnt[i^1]<=numMove[other]) return (other);
    return (lastMove);
}
int main(void) {
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt[2];
    REP(i,2) cnt[i]=0;
    REP(love,n) {
        int t;
        scanf("%d",&t);
        cnt[t%2]++;
    }
    cout<<player[winner(cnt,k)]<<endl;
    return 0;
}
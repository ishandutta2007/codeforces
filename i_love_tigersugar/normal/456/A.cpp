#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
map<int,int> mp;
int main(void) {
    int n;
    scanf("%d",&n);
    FOR(i,1,n) {
        int a,b;
        scanf("%d%d",&a,&b);
        mp[a]=b;
    }
    int prev=-1;
    FORE(it,mp) {
        if (prev>=0 && it->second<prev) {
            printf("Happy Alex");
            return 0;
        }
        else prev=it->second;
    }
    printf("Poor Alex");
    return 0;
}
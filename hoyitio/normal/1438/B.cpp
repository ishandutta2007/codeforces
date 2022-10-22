#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
map<int, int> mp;
int main()
{
    int T; cin>>T;
    while(T--){
        int n;
        scanf("%d", &n);
        mp.clear();
        int x;
        int flag = 0;
        fors(i,1,n+1)
            {scanf("%d", &x); if(++mp[x] == 2) flag = 1;}

        if(flag) printf("YES\n");
        else printf("NO\n");

    }
}
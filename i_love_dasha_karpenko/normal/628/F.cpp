#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e4+7;
int n,b,q,cnt[N];
pair<int,int> A[N];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>b>>q;
    for(int i = 1;i<=q;++i){
        cin>>A[i].first>>A[i].second;
    }
    A[++q] = {b,n};
    sort(A+1,A+1+q);
    int masksz = 1<<5;
    int need = n/5;
    for(int mask = 1;mask<masksz;++mask){
        int sum = 0;
        for(int bit = 0;bit<5;++bit){
            if (!(mask&(1<<bit)))
                continue;

            for(int i = 1;i<=q;++i){
                if (A[i].second<A[i-1].second){
                    cout<<"unfair\n";
                    exit(0);
                }
                int l = A[i-1].first+1,r = A[i].first;
                int qnt;
                if (l%5!=bit){
                    l+=(5+bit-l%5)%5;
                    if (l>r)
                        qnt = 0;
                    else qnt = 1+(r-l)/5;
                }
                else{
                    qnt = 1;
                    ++l;
                    qnt+=(r-l+1)/5;
                }
                int g = min(A[i].second-A[i-1].second-cnt[i],qnt);
                sum+=g;
                cnt[i]+=g;
            }

        }
        if (sum<__builtin_popcount(mask)*need){
            cout<<"unfair\n";
            exit(0);
        }
        for(int i = 1;i<=q;++i)
            cnt[i] = 0;
    }
    cout<<"fair\n";
    return 0;
}
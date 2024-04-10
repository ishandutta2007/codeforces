#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 2e5+2;
int main() {

    int n,q; cin >> n >> q;
    int offset = min(-1,-n+13);
    vector<long long> a(n+1);
    for(int i=1;i<=n;++i) {
        a[i]+=i+a[i-1];
    }
    long long perm = 0;
    auto nth_permutation = [&](long long index, int size, long long start) {
        vector<long long> ans;
        vector<long long> tmp;
        long long fact=1;
        for(long long i=1;i<=size;++i) {
            tmp.push_back(i+start);
            fact*=i;
        }
        for (int i = 1; i <= size; i++) {
            fact/=tmp.size();
            int item = (index/fact);
            ans.push_back( tmp[item]);
            index = index%fact;
            tmp.erase(tmp.begin()+item);
        }
        return ans;
    };
    vector<long long> changing = nth_permutation(0,min(14,n),max(n-14,0));
    for(int i=0;i<q;++i) {
        int ty; cin >> ty;
        if(ty==1) {
            int l, r;
            cin >> l >> r;
            long long ans=0;
            if(l<=n-14) {
                ans-=a[l-1];
                if(r<=n-14) {
                    ans+=a[r];
                    cout << ans << endl;
                    continue;
                } else ans+=a[n-14];
            }
            for(int j=max(l,n-13);j<=r;++j) {
                ans+=changing[j+offset];
            }
            cout << ans << endl;
        } else {
            int x; cin >> x;
            perm+=x;
            changing = nth_permutation(perm,min(14,n),max(n-14,0));
        }
    }

    
}
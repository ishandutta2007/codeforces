#include <iostream>
#include <vector>
using namespace std;
const int mxN = 1e5;
int main() {
    int t; cin >> t;
    while(t--) {
        int q;
        long long p,ans=1; cin >> p >> q;
        for(long long i=2;i*i<=q;++i) {
            int count=0;
            while(q%i==0) {
                q /=i;
                count++;
            }
            if(count) {
                int count2=0;
                long long tmp = p;
                while(tmp%i==0) {
                    tmp/=i;
                    count2++;
                }
                int toadd = min(count2,count-1);
                while(toadd--) {
                    tmp*=i;
                }
                ans = max(ans,tmp);
                if(ans==p) break;
            }
        }
        if(q!=1) {
            // iq is een priemgetal
            int i = q;
            long long tmp = p;
            while(tmp%i==0) {
                tmp/=i;
            }
            ans = max(ans,tmp);
        }
        cout << ans << endl;
    }
}
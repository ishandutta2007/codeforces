#include <iostream>
#include <vector>
using namespace std;
const int mxN = 1e5;
int main() {

    int t;
    cin >> t;
    while(t--) {
        long long p,q,ans=1; cin >> p >> q;
        int iq = q;
        for(long long i=2;i*i<=iq;++i) {
            int count=0;
            if(i*i>iq) {
                if(iq==1) break;
                count=1;
                i=iq;
            } else {
                while(true) {
                    int tmp = iq/i;
                    if(tmp*i!=iq) break;
                    //cout << "found divisor" << endl;
                    iq = tmp;
                    count++;
                }
            }
            if(count!=0) {
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
        if(iq!=1) {
            int count2=0;
            int i = iq;
            long long tmp = p;
            while(tmp%i==0) {
                tmp/=i;
                count2++;
            }
            int toadd = min(count2,0);
            while(toadd--) {
                tmp*=i;
            }
            ans = max(ans,tmp);
        }
        cout << ans << endl;
    }
}
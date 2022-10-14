#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
	long long l, r;
    cin >> l >> r;
    int i=0;
    while((1LL<<i)<=r) {
        ++i;
    }
    --i;
    long long ans=0;
    while(i>=0) {
        if((1LL<<i)&r and !((1LL<<i)&l)) {
            for(int j=0;j<=i;++j) {
                ans|=1LL<<j;
            }
        }
        --i;
    }
    cout << ans << endl;
}
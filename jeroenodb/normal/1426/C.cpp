#include <iostream>
#include <math.h>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >>n;
        if(n==1) cout << "0\n";
        else cout << (int)ceil((2*(sqrt(n)-1))) << endl;
    }

    
}
#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;
    if (k == 1)
        cout<<n;
    else{
        long long t = 1;
        while (n >= t)
            t *= 2;
        cout<<t-1<<endl;
    }
    return 0;
}
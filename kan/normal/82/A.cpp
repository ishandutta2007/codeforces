#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long cur=0;
    long long curk=1;
    while (cur+curk*5<n)
    {
        cur=cur+5*curk;
        curk*=2;
    }
    long long ans=(n-cur-1)/curk;
    if (ans==0) cout << "Sheldon";
    if (ans==1) cout << "Leonard";
    if (ans==2) cout << "Penny";
    if (ans==3) cout << "Rajesh";
    if (ans==4) cout << "Howard";
    return 0;
}
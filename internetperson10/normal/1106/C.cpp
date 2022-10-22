#include <iostream>
#include <algorithm>

using namespace std;

long long int hw[300030];

int main() {
    int n;
    long long int s=0;
    cin >> n;
    for(int a=0; a<n; a++)
        cin >> hw[a];
    sort(hw+0, hw+n);
    for(int a=0; a<n/2; a++)
        s+=((hw[a]+hw[n-a-1])*(hw[a]+hw[n-a-1]));
    cout << s;
}
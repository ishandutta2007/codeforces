#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
ll arr[202020];
int dig(int n) {
    if (n==0)
        return 1;
    int ans = 0;
    while (n) {
        n/=10;
        ++ans;
    }
    return ans;
}
int pow(int n, int k) {
    int ans = 1;
    for (int i=0; i<k; i++) {
        ans *= n;
    }
    return ans;
}
int maxp(int n) {
    if (n<=9)
        return n;
    int d = dig(n);
    int maxi = pow(9, d-1);

    for (int i=1; i<d; i++) {
        maxi = max(maxi, maxp(n%pow(10, i))*maxp(n/pow(10, i)));
        maxi = max(maxi, maxp(pow(10, i)-1)*maxp(n/pow(10, i)-1));
    }
    return maxi;
}
int main() {
    scanf("%d", &n);

    printf("%d", maxp(n));

}
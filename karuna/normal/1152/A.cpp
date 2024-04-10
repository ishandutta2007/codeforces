#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int arr[1010101];
int brr[1010101];
int main() {
    scanf("%d%d", &n, &m);
    int cnt1=0, cnt2=0;
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i]%2==1) cnt1++;
        else cnt2++;
    }
    int cnt3=0, cnt4=0;
    for (int i=0; i<m; i++) {
        scanf("%d", &brr[i]);
        if (brr[i]%2==1) cnt3++;
        else cnt4++;
    }
    printf("%d", min(cnt1, cnt4)+min(cnt2, cnt3));

}
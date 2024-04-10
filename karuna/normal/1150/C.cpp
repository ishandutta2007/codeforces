#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int cnt1=0, cnt2=0;
bool sieve[404040] = {true, true};
int main() {
    scanf("%d", &n);

    int k;
    for (int i=0; i<n; i++) {
        scanf("%d", &k);
        if (k==1) cnt1++;
        else cnt2++;
    }


    if (cnt2>0 && cnt1>0) {
        printf("2 ");
        printf("1 ");
        cnt2--;
        cnt1--;

        while (cnt2--) printf("2 ");
        while (cnt1--) printf("1 ");
    }
    if (cnt1==0) while(cnt2--) printf("2 ");
    if (cnt2==0) while(cnt1--) printf("1 ");
}
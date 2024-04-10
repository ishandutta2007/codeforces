#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int arr[101010];
int main() {
    int c1, c2, c3, c4;
    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);

    if (c1 == c4 && (c3==0 || c1!=0)) {
        printf("1");
    }
    else
        printf("0");

}
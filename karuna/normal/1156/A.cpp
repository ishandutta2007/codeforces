#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int arr[10101];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int cnt = 0;
    bool flag = false;
    for (int i=0; i<n-1; i++) {
        if (arr[i] == 1) {
            if (arr[i+1]==3) cnt+=4;
            else if (arr[i+1]==2 && flag) cnt+=2;
            else cnt+=3;

            if (flag) flag=false;
        }
        if (arr[i] == 2) {
            if (arr[i+1]==1) cnt +=3;
            else cnt=-1;
            if (flag) flag=false;
        }
        if (arr[i] == 3) {
            if (flag) flag=false;
            if (arr[i+1]==1) {cnt+=4; flag=true;}
            if (arr[i+1]==2) cnt=-1;
        }

        if (cnt==-1) break;
    }

    if (cnt!=-1) {
        printf("Finite\n");
        printf("%d", cnt);

    }
    else printf("Infinite");
}
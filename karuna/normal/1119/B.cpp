#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, h;
int arr[202020];
int main() {
    scanf("%d%d", &n, &h);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }

    int lo = 1, hi = n;
    vector<int> v;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        for (int i=1; i<=mid; i++)
            v.push_back(arr[i]);

        sort(v.begin(), v.end());

        int l=0, r=0, cur=mid-1;
        bool b = false;
        while (1){
            if (l==r)
                l+=v[cur];
            else
                r=l;
            --cur;

            if (l>h) break;
            if (cur<0) {
                b = true;
                break;
            }
        }

        v.clear();
        if (b) {
            lo = mid;
            continue;
        }
        else {
            hi = mid-1;
            continue;
        }
    }
    printf("%d", lo);
}
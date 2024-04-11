#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int SQRT = 500;
int n, a[200005];

inline int par(int x, int k){
    return (x - 2 + k) / k;
}

deque<int> dq;
int ret[200005];

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=SQRT && i<n; i++) {
        int ret = 0;
        for (int j=2; j<=n; j++) {
            if(a[par(j,i)] > a[j]) ret++;
        }
        printf("%d ",ret);
    }
    if(SQRT + 1 >= n){
        return 0;
    }
    for (int i=1; ; i++) {
        // parent = i from 501 - ary heap and beyond.
        int cnt = 0;
        dq.clear();
        int curr_buck = SQRT + 1;
        if(2 + curr_buck * (i-1) > n) break;
        for (int j=2 + curr_buck * (i-1); j<=curr_buck * i + 1 && j <= n; j++) {
            dq.push_back(a[j]);
            if(a[j] < a[i]) cnt++;
        }
        int ed = curr_buck * i + 2;
        ret[curr_buck++] += cnt;
        while (curr_buck < n) {
            for (int k=0; k<i-1; k++) {
                if(dq.empty()) break;
                if(a[i] > dq.front()) cnt--;
                dq.pop_front();
            }
            for (int k=0; k<i && ed <= n; k++) {
                if(a[i] > a[ed]) cnt++;
                dq.push_back(a[ed++]);
            }
            ret[curr_buck++] += cnt;
        }
    }
    for (int i=SQRT+1; i<n; i++) {
        printf("%d ",ret[i]);
    }
}
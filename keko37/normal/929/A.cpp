#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iostream>

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,k,cur,a[N],sol = 0;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    cur = a[0];
    for(int i = 1;i<n;i++){
        if(a[i] - cur > k) cur = a[i - 1],sol++;
        if(a[i] - a[i - 1] > k){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",sol + 1);
}
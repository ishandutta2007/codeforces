#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef pair<double, double> pr;

int n, a[500005];
int d[500005];

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(i) d[i] = a[i] ^ a[i-1];
    }
    int ret = 0;
    for(int i=1; i<n; i++){
        if(!d[i]) continue;
        int e = i;
        while(e < n && d[e]) e++;
        ret = max(ret, (e - i) / 2);
        // [i, e]
        for(int j=i; j<e; j++){
            d[j] = 0;
        }
        if(e%2 != i%2){
            d[(e+i)/2] = 1;
        }
        i = e-1;
    }
    printf("%d\n%d ",ret,a[0]);
    int p = a[0];
    for(int i=1; i<n; i++){
        p ^= d[i];
        printf("%d ",p);
    }
}
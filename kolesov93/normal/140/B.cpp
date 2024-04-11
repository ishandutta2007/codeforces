#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;

#define N 333

int a[N],b[N][N],w[N];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    int n;
    cin >> n;
    
    
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) { 
            scanf("%d",&b[j][i]);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        w[a[i]] = i;
    }
    
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (b[j][i] == j) continue;
            
            bool cool = true;
            for (int q = w[b[j][i]] - 1; q; q--)
                if (a[q] < b[j][i] && a[q] != j) {
                    cool = false;
                    break;
                }
                if (cool) {
                    cout << b[j][i] << " ";
                    break;
                }
        }
    }
    
    cout << endl;
    
    return 0;
}
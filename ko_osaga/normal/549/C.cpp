#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int odd, even, n, k;

int my_solve(int i, int j){
    if(k %2 == 1 && k == i && j == 0) return 1;
    if(k % 2 == 0){
        if(i + j == k){
            return i%2;
        }
        else if((i - j)%2 != 0 && abs(i - j) < k){
            return 1;
        }
        return 0;
    }
    if(k % 2 == 1){
        int ret = 0;
        if(i - j >= k) ret = 1;
        else if(i - j <= -k) ret = 0;
        else if((i - j) % 2) ret = 0;
        else ret = 1;
        if(j % 2 == 1 && i + j == k){
            ret ^= 1;
        }
        if((i + j) <= k) ret ^= 1;
        return ret;
    }
    return 2;
}

int main(){
    scanf("%d %d",&n,&k);
    int i = 0, j = 0;
    while (n--) {
        int t;
        scanf("%d",&t);
        if(t&1) i++;
        else j++;
    }
    puts(my_solve(i,j)?"Stannis":"Daenerys");
}
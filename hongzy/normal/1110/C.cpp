#include <algorithm>
#include <cstdio>
using namespace std;

const int num[24] = {3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535,
 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431};
const int ans[24] = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525,
 299593, 1398101, 178481, 5592405, 1082401};

int main() {
    int q, x;
    scanf("%d", &q);
    while(q --) {
        scanf("%d", &x); bool tag = 0;
        for(int i = 0; i < 24; i ++)
            if(x == num[i]) printf("%d\n", ans[i]), tag = 1, i = 24;
        if(!tag) {
            for(int i = 0; i < 24; i ++)
                if(num[i] > x) printf("%d\n", num[i]), i = 24;
        }
    }
    return 0;
}
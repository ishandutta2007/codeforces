#include <cstdio>
#include <algorithm>
#define x first
#define y second
#include <queue>

using namespace std;

int n, k;
pair < long long, int > x[300005];

queue < long long > Q;
int sz;
long long csum;
long long csol;
void remove(){
     long long x = Q.front();
     Q.pop();
     csum -= x;
     --sz;
     csol -= csum - sz * x;
}
void add(long long x){
     csol += (x * sz - csum);
     csum += x;
     ++sz;
     Q.push(x);
     if (sz > k) remove();
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%I64d", &(x[i].x));
        x[i].y = i;
    }
    scanf("%d", &k);
    sort(x, x + n);
    long long r = 9200000000000000000LL, rp = 0;
    for (int i = 0; i < n; ++i){
        //printf("%d\n", x[i].y);
        add(x[i].x);
        if (sz != k) continue;
        if (r > csol){r = csol; rp = i;}
    }
    //printf("%I64d\n", csol);
    
    for (int i = rp - k + 1; i <= rp; ++i) printf("%d ", x[i].y + 1);
    return 0;
}
#include <cstdio>
#include <queue>

using namespace std;

int k, n1, n2, n3, t1, t2, t3;

queue < int > q1, q2, q3;

int main(){
    scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
    int r = -1;
    for (int t = 0; k; ++t){
        while (q1.size() != 0 && q1.front() == t) q1.pop();
        while (q2.size() != 0 && q2.front() == t) q2.pop();
        while (q3.size() != 0 && q3.front() == t) q3.pop();
        
        while (k){
        if (q1.size() == n1) break;
        if (q2.size() == n2) break;
        if (q3.size() == n3) break;
        q1.push(t + t1);
        q2.push(t + t2);
        q3.push(t + t3);
        r = t + t1 + t2 + t3;
        --k;
        }
    }
    printf("%d\n", r);
    return 0;
}
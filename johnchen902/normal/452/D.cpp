#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int k, n1, n2, n3, t1, t2, t3;
    scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
    deque<int> m1, m2, m3;
    for(int i = 0; i < n1; i++) m1.push_back(0);
    for(int i = 0; i < n2; i++) m2.push_back(0);
    for(int i = 0; i < n3; i++) m3.push_back(0);

    int t;
    for(t = 0; k || m3.back() > t; t++) {
        while(k && m1.front() <= t && m2.front() <= t + t1 && m3.front() <= t + t1 + t2) {
            m1.pop_front(); m1.push_back(t + t1);
            m2.pop_front(); m2.push_back(t + t1 + t2);
            m3.pop_front(); m3.push_back(t + t1 + t2 + t3);
            k--;
        }
    }
    printf("%d\n", t);
}
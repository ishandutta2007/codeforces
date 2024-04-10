#include <cstdio>
#include <algorithm>
using namespace std;

int w, m, d[99], cnt;

int main(){
    scanf("%d%d", &w, &m);
    while(m){
        d[cnt++] = m % w;
        m /= w;
    }
    for(int i = 0; i < cnt; i++){
        if(d[i] > 1 && d[i] < w - 1) {puts("No"); return 0;}
        if(d[i] >= w - 1) d[i + 1]++;
    }
    puts("Yes");
}
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c;

int main(){
    scanf("%d%d%d", &a, &b, &c);
    for(int t = 0; t <= 10000; t++){
        if(c - a * t >= 0 && (c - a * t) % b == 0){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
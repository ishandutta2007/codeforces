#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    for(int i = 20; i >= 1; i--) if(n & (1 << (i - 1))) printf("%d ", i);
}
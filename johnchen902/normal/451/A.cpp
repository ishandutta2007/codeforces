#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    puts(min(n, m) % 2 ? "Akshat" : "Malvika");
}
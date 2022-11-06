#include <cstdio>

using namespace std;

int main() {
int T;
scanf("%d", &T);
while(T--){
int x, y;
scanf("%d%d", &x, &y);
printf("%d %d\n", x, x + x);
}
}
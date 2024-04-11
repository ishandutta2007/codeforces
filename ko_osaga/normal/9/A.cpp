#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int x, int y){
    return y ? gcd(y,x%y) : x;
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int cnt = 7 - max(x,y);
    printf("%d/%d",(cnt / gcd(cnt,6)),6 / gcd(cnt,6));
}
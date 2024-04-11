#include <cstdio>
long long a,b;

int main(){
    scanf("%lld %lld",&a,&b);
    if(a < 4){
        puts("YES");
        return 0;
    }
    while(b){
        if(b % a == 1){
            b--;
        }
        else if(b % a == a - 1){
            b++;
        }
        else if(b % a != 0){
            puts("NO");return 0;
        }
        b /= a;
    }
    puts("YES");
}
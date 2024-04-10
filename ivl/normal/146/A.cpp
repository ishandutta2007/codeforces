#include <cstdio>

using namespace std;

int n;
char num[55];

int main(){
    scanf("%d", &n);
    scanf("%s", num);
    bool test = true;
    for (int i = 0; i < n; ++i){
        test &= (num[i] == '4') || (num[i] == '7');
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; ++i){
        sum1 += num[i] - '0';
        sum2 += num[n - i - 1] - '0';
    }
    if (test && sum1 == sum2){
       printf("YES\n");
    }
    else {
         printf("NO\n");
    }
    return 0;
}
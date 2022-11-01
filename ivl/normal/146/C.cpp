#include <cstdio>

using namespace std;

int a, b, s;
char ucit[100005];
int an[100005], bn[100005];
bool no[100005];

int main(){
    scanf("%s", ucit);
    for (int i = 0; i < 100003; ++i){
        if (ucit[i] >= '0' && ucit[i] <= '9'){
           an[i] = ucit[i] - '0';
        }
    }
    scanf("%s", ucit);
    for (int i = 0; i < 100003; ++i){
        if (ucit[i] == 0){
           s = i;
           break;
        }
        if (ucit[i] >= '0' && ucit[i] <= '9'){
           bn[i] = ucit[i] - '0';
        }
    }
    int num4 = 0, num7 = 0;
    for (int i = 0; i < s; ++i){
        if (an[i] != bn[i]){
           if (an[i] == 4){
              ++num4;
           }
           else {
                ++num7;
           }
           no[i] = true;
        }
    }
    int rez = num4;
    if (num7 > rez){
       rez = num7;
    }
    printf("%d\n", rez);
    //while (true);
    return 0;
}
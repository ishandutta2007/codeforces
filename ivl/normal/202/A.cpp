#include <cstdio>

using namespace std;

char word[15];

int main(){
    scanf("%s", word);
    char curr = word[0];
    int amm = 1;
    for (int i = 1; word[i] >= 'a' && word[i] <= 'z'; ++i){
        if (word[i] == curr){
           ++amm;
        }
        if (word[i] > curr){
           curr = word[i];
           amm = 1;
        }
    }
    for (int i = 0; i < amm; ++i){
        printf("%c", curr);
    }
    printf("\n");
    return 0;
}
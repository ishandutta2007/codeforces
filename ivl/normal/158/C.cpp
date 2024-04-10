#include <cstdio>

using namespace std;

int n;
char com[55][5];
char nas[55][205];
char dirr[10005];
char next[205];
int size = 1;

void clear(){
     for (int i = 1; i < 10000; ++i){
         dirr[i] = '\0';
     }
     size = 1;
}

void back(){
     dirr[size - 1] = '\0';
     --size;
     for (; dirr[size - 1] != '/'; --size){
         dirr[size - 1] = '\0';
     }
}

void add(){
     for (int i = 0; next[i] != '\0'; ++i){
         dirr[size++] = next[i];
     }
     dirr[size++] = '/';
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%s", com + i);
        if (com[i][0] == 'c'){
           scanf("%s", nas + i);
        }
    }
    dirr[0] = '/';
    for (int i = 0; i < n; ++i){
        if (com[i][0] == 'p'){
           printf("%s\n", dirr);
        }
        else {
             int pos = 0;
             if (nas[i][0] == '/'){
                clear();
                ++pos;
             }
             for (int j = pos; nas[i][j] == '/' || (nas[i][j] >= 'a' && nas[i][j] <= 'z') || nas[i][j] == '.'; ++j){
                 if (nas[i][j] == '.'){
                    back();
                    j += 2;
                 }
                 else {
                      int pom = j;
                      for (; nas[i][j] >= 'a' && nas[i][j] <= 'z'; ++j){
                          next[j - pom] = nas[i][j];
                      }
                      //printf("%s %d\n", next, j);
                      add();
                      for (int k = 0; k < 203; ++k){
                          next[k] = '\0';
                      }
                 }
             }
        }
    }
    //while (true);
    return 0;
}
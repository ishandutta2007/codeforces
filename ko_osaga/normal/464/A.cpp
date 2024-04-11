#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,p;
char str[1005];

void process(int pos){
    str[pos]++;
    while (str[pos] < 'a' + p) {
        if((pos < 1 || str[pos-1] != str[pos]) && (pos < 2 || str[pos-2] != str[pos])) break;
        str[pos]++;
    }
    if(str[pos] == 'a' + p){
        if(pos == 0){
            puts("NO");
            exit(0);
        }
        str[pos] = 'a'-1;
        process(pos-1);
        process(pos);
    }
}
int main(){
    scanf("%d %d",&n,&p);
    scanf("%s",str);
    process(n-1);
    puts(str);
}
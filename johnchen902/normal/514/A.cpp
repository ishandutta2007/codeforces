#include <cstdio>
using namespace std;
int main(){
    bool start = true;
    char c;
    while((c = getchar()) != EOF && c != '\n') {
        if(c >= '5' && (!start || c != '9'))
            c = ('9' + '0') - c;
        putchar(c);
        start = false;
    }
}
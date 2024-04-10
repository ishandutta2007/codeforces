#include <cstdio>

char a[22], b[22];
int ac, bc;
int ap, bp;

int main(){
    scanf("%s%s", a, b);
    for(int i = 0; a[i]; i += 2){
        ap = a[i] == '8' ? 0 : a[i] == '(' ? 1 : 2;
        bp = b[i] == '8' ? 0 : b[i] == '(' ? 1 : 2;
        if((ap == 0 && bp == 1) || (ap == 1 && bp == 2) || (ap == 2 && bp == 0)) bc++;
        else if(ap != bp) ac++;
    }
    if(ac > bc) puts("TEAM 1 WINS");
    else if(ac < bc) puts("TEAM 2 WINS");
    else puts("TIE");
}
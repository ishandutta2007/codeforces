#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
bool a[4][11];
void occur(void) {
    REP(j,11) REP(i,4) if (j==0 || i!=2)
        if (!a[i][j]) {
            a[i][j]=true;
            return;
        }
    assert(false);
}
int main(void) {
    int n;
    scanf("%d",&n);
    REP(zz,n) occur();
    printf("+------------------------+\n");
    printf("|");
    REP(j,11) printf("%c.",a[0][j]?'O':'#');
    printf("|D|)\n");
    printf("|");
    REP(j,11) printf("%c.",a[1][j]?'O':'#');
    printf("|.|\n");
    printf("|");
    if (a[2][0]) printf("O"); else printf("#");
    printf(".......................|\n");
    printf("|");
    REP(j,11) printf("%c.",a[3][j]?'O':'#');
    printf("|.|)\n");
    printf("+------------------------+\n");
    return 0;
}
/*
+------------------------+
|O.O.O.#.#.#.#.#.#.#.#.|D|)
|O.O.O.#.#.#.#.#.#.#.#.|.|
|O.......................|
|O.O.#.#.#.#.#.#.#.#.#.|.|)
+------------------------+
*/
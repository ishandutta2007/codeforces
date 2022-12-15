#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e8+4;
int N, H, A, B, Q;

int main(){
    scanf("%d %d %d %d %d", &N, &H, &A, &B, &Q);
    while(Q--){
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        if(sx==ex) printf("%d\n", abs(sy-ey));
        else{
            if(sy<A&&ey<A) printf("%d\n", abs(sx-ex)+A-sy+A-ey);
            else if(sy>B&&ey>B) printf("%d\n", abs(sx-ex)+sy-B+ey-B);
            else printf("%d\n", abs(sx-ex)+abs(sy-ey));
        }
    }

    return 0;
}
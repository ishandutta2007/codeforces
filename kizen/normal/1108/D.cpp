#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
char s[NS];
int d[NS][4], from[NS][4];

void out(int x, int y){
    if(x==0){
        printf("%c", y==0? 'R':y==1? 'G':'B');
    }
    else{
        out(x-1, from[x][y]);
        printf("%c", y==0? 'R':y==1? 'G':'B');
    }
}

int main(){
    scanf("%d", &N);
    scanf("%s", s);
    d[0][0] = s[0]!='R';
    d[0][1] = s[0]!='G';
    d[0][2] = s[0]!='B';
    for(int i=1;i<N;++i){
        from[i][0] = d[i-1][1]<d[i-1][2]? 1:2;
        from[i][1] = d[i-1][0]<d[i-1][2]? 0:2;
        from[i][2] = d[i-1][0]<d[i-1][1]? 0:1;
        d[i][0] = min(d[i-1][1], d[i-1][2])+(s[i]!='R');
        d[i][1] = min(d[i-1][0], d[i-1][2])+(s[i]!='G');
        d[i][2] = min(d[i-1][0], d[i-1][1])+(s[i]!='B');
    }
    int num;
    if(d[N-1][0]<=d[N-1][1]&&d[N-1][0]<=d[N-1][2]) num = 0;
    else if(d[N-1][1]<=d[N-1][0]&&d[N-1][1]<=d[N-1][2]) num = 1;
    else num = 2;
    printf("%d\n", d[N-1][num]);
    out(N-1, num);
    return 0;
}
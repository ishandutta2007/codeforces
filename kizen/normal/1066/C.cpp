#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
int L[NS], R[NS];
int pos[NS], pp[NS];
char poc[NS];

int main(){
    scanf("%d", &N);
    int pn = 0;
    for(int i=1;i<=N;++i){
        char c; int num;
        scanf(" %c %d", &c, &num);
        L[i] = L[i-1], R[i] = R[i-1];
        if(c!='?') pos[num] = pn, pp[num] = i;
        if(c=='L'){
            pos[num] = ++pn; ++L[i]; poc[num] = c;
        }
        else if(c=='R'){
            pos[num] = ++pn, ++R[i]; poc[num] = c;
        }
        else{
            if(poc[num]=='L'){
                printf("%d\n", min(L[i]-L[pp[num]], R[i]-R[pp[num]]+pos[num]-1));
            }
            else{
                printf("%d\n", min(R[i]-R[pp[num]], L[i]-L[pp[num]]+pos[num]-1));
            }
        }
    }
    return 0;
}
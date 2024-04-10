#include <bits/stdc++.h>

using namespace std;

char A[1004], B[1004];

int main(){
    scanf("%s %s", A, B);
    int N = strlen(A), M = strlen(B);
    if(N!=M){
        puts("No"); return 0;
    }
    for(int i=0;i<N;++i){
        int a = (A[i]=='a')||(A[i]=='e')||(A[i]=='i')||(A[i]=='o')||(A[i]=='u');
        int b = (B[i]=='a')||(B[i]=='e')||(B[i]=='i')||(B[i]=='o')||(B[i]=='u');
        if(a!=b){
            puts("No"); return 0;
        }
    }
    puts("Yes");
    return 0;
}
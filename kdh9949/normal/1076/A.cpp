#include <bits/stdc++.h>
using namespace std;

int n;
char s[200005];

int main(){
    scanf("%d%s", &n, s);
    for(int i=0; i<n; i++){
        if(s[i]>s[i+1]){
            for(int j=0; j<n; j++) if(j!=i) putchar(s[j]);
            return 0;
        }
    }
}
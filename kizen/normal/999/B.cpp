#include <bits/stdc++.h>

using namespace std;

int N;
char arr[104];
vector < int > rev;

int main(){
    scanf("%d", &N);
    scanf("%s", arr+1);
    for(int j=1;j<=N;j++) if(N%j==0) rev.push_back(j);
    for(int i=0;i<(int)rev.size();++i){
        for(int j=1;j<=rev[i]/2;j++) swap(arr[j], arr[rev[i]-j+1]);
    }
    for(int i=1;i<=N;i++) printf("%c", arr[i]);

    return 0;
}
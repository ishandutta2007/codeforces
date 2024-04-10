#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long n,t1,t2,t3,t4;
char str[1001];
int main(){
    cin>>n;
    scanf("%s",str);
    if(n==1){
        puts("NO");
        return 0;
    }
    for(int i=0;str[i+1];i++)
        if(str[i]!=str[i+1]){
            puts("YES");
            printf("%c%c",str[i],str[i+1]);
            return 0;
        }
    puts("NO");
}
#include<bits/stdc++.h>
using namespace std;

int n;
int a,b,c,d;
pair<int,int> guard[5];

int main(){ 
    scanf("%d",&n);
    
for (int i = 0; i < 4; ++i) {
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for (int j = 0; j <= n; ++j) {
    
    int k = n - j;
    
    if (j >= min(a,b) && k >= min(c,d)) {

    printf("%d %d %d\n",i+1,j,k);
    
    return 0;
}
}
}
puts("-1");
}
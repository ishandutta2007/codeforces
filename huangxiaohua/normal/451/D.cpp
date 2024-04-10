#include<iostream>
long long i,a[99][2],r,w;main(){while(char s=getchar()){if(s<'a'){return std::cout<<w<<' '<<r,0;}r+=++a[s][i^=1];w+=a[s][1-i];}}
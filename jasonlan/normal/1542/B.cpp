#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int a,b,n;
map<int,int> mp;
typedef long long ll;
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
void proc(){
    n=read();a=read();b=read();
    long long res=1;
    for(int i=0;;++i){
        if(n%b==res%b){
            puts("Yes");return;
        }
        res*=a;
        if(res>n||a==1){
            puts("No");return;
        }
    }
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}
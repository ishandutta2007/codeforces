#include<bits/stdc++.h>
using namespace std;
int L,n;
char a[100001];
int main(){
    scanf("%d%s",&L,a);
    n=strlen(a);
    reverse(a,a+n);
    for(int i=0;i<n;++i){
        a[i]-='0';
    }
    ++a[0];
    for(int i=0;i<n;++i){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[n]){
        ++n;
    }
    if(n%L!=0){
        int t=(n+L-1)/L;
        for(int i=0;i<t;++i){
            putchar('1');
            for(int j=0;j<L-1;++j){
                putchar('0');
            }
        }
        puts("");
        return 0;
    }
    reverse(a,a+n);
    int t=n/L;
    for(int i=1;i<t;++i){
        bool ok=true;
        for(int j=0;j<L;++j){
            if(a[i*L+j]>a[j]){
                ok=false;
                break;
            }else if(a[i*L+j]<a[j]){
                break;
            }
        }
        if(!ok){
            ++a[L-1];
            for(int j=L-1;j>0;--j){
                a[j-1]+=a[j]/10;
                a[j]%=10;
            }
            break;
        }
    }
    for(int i=0;i<t;++i){
        for(int j=0;j<L;++j){
            putchar(a[j]+'0');
        }
    }
    puts("");
    return 0;
}
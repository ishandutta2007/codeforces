#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n<=26){
            for(int i=0;i<n;i++) printf("%c",(char)(i+'a'));
            puts("");
        }else{
            if(n%2==0){
                int k=n/2;
                for(int i=1;i<k;i++) printf("a");
                printf("b");
                for(int i=1;i<=k;i++) printf("a");
                puts("");
            }else{
                int k=(n-5)/2;
                printf("a");
                for(int i=1;i<=k;i++) printf("b");
                printf("c");
                for(int i=1;i<=k+1;i++) printf("b");
                printf("aa");
                puts("");
            }
        }
    }
    return 0;
}
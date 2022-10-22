#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
int bit[mn],v[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int zero;
bool rev;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)up(i,1),v[i]=1;
    while(q--){
        int a,b;
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&a);
            if(a>n/2){
                if(!rev)zero+=n+1;
                else zero-=n+1;
                rev^=1;
                a=n-a;
            }
            if(!rev){
                for(int i=1;i<=a;i++){
                    v[zero+2*a+1-i]+=v[zero+i];
                    up(zero+2*a+1-i,v[zero+i]);
                    up(zero+i,-v[zero+i]);
                    v[zero+i]=0;
                }
                zero+=a;
            }else{
                for(int i=1;i<=a;i++){
                    v[zero-(2*a+1-i)]+=v[zero-i];
                    up(zero-(2*a+1-i),v[zero-i]);
                    up(zero-1,-v[zero-i]);
                    v[zero-i]=0;
                }
                zero-=a;
            }
            n-=a;
        }else{
            scanf("%d%d",&a,&b);
            if(rev){
                a=-a-1;
                b=-b-1;
                swap(a,b);
            }
            a+=zero,b+=zero;
            printf("%d\n",qu(b)-qu(a));
        }
    }
}
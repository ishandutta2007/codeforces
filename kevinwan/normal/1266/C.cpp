#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;

int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    if(r==1&&c==1)printf("0");
    else if(r==1){
        for(int i=0;i<c;i++)printf("%d ",i+2);
    }
    else if(c==1){
        for(int i=0;i<r;i++)printf("%d\n",i+2);
    }
    else{
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%d ",(i+1)*(r+1+j));
            }
            printf("\n");
        }
    }
}
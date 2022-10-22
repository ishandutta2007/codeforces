#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int main(){
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            printf("%d",i);
            n/=i;
        }
    }
    if(n>1)printf("%d",n);
}
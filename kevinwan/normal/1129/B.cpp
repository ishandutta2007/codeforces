#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=5010;
vector<int> k[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int k;
    cin>>k;
    k+=2000;
    printf("2000\n");
    printf("-1 ");
    for(int i=1;i<2000;i++){
        if(k>=1000000)printf("1000000 "),k-=1000000;
        else printf("%d ",k),k=0;
    }
}
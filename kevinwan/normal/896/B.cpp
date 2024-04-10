#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
const int mn=2e5+10;
int num[mn];
int n,m,c;
bool comp(){
    for(int i=1;i<n;i++){
        if(num[i]>num[i+1])return 0;
        if(!num[i])return 0;
    }
    return num[n];
}
void place(int a,int b){
    num[a]=b;
    cout<<a<<endl;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m>>c;
    int i;
    while(!comp()){
            int x;
        cin>>x;
        if(x>c/2){
            for(i=n;i;i--){
                if(!num[i]||num[i]<x){
                        place(i,x);
                        break;
                }
            }
        }
        else{
            for(i=1;i<=n;i++){
                if(!num[i]||num[i]>x){
                        place(i,x);
                        break;
                }
            }
        }
    }
}